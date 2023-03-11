#include"pr.h"

void p_create(char* fname)
{
    FILE* fp;
    fopen_s(&fp, fname, "w");
    if (fp == NULL)
    {
        cout << "Error creating/opening file" << endl;
        return;
    }
    else
    {
        cout << "File is successfully opened/created" << endl;
    }
    std::fclose(fp);
}

void p_delete(const char* fname)
{
    int status = 0;
    status = remove(fname);                                                 //видалення файл
    if (status == 0)                                                        //перевірка чи видалено файл
        cout << "\nFile Deleted Successfully!";
    else
        cout << "\nError Occurred!" << endl;
}

void p_read_data(const char* fname)
{
    FILE* fp;
    fopen_s(&fp, fname, "r");                                               //відкриваємо файл для читання
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        return;
    }

    char text;
    while ((text = fgetc(fp)) != EOF) {                                     //посимвольне зчитування з файлу
        cout << text;
    }

    std::fclose(fp);
}

void p_write_data(const char* fname)
{
    FILE* fp;
    fopen_s(&fp, fname, "w");
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        return;
    }

    cout << "Write your text. When you finish write < end > ";
    char* text = new char[256];
    while (true) {
        cin.getline(text, 255);
        if (strcmp(text, "end") == 0) {
            break;
        }
        fprintf(fp, "%s\n", text);
    }

    std::fclose(fp);
}

void p_app_data(const char* fname)
{
    FILE* fp;
    fopen_s(&fp, fname, "a");
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        return;
    }
    cout << "Write your text. When you finish write < end > ";
    char* text = new char[256];
    while (true) {
        cin.getline(text, 255);
        if (strcmp(text, "end") == 0) {
            break;
        }
        fprintf(fp, "%s\n", text);
    }

    std::fclose(fp);
}

bool find_operators(const char* line, std::smatch& match) {
    const regex pattern("(\\w+)\\s*=\\s*\\1\\s*\\+\\s*(\\d+)\\s*;");            //створення шаблону для пошуку
    const string str(line);
    return regex_search(str.begin(), str.end(), match, pattern);
}

char* replace_operators(const char* line)
{
    const char* pattern = "(\\w+)\\s*=\\s*\\1\\s*\\+\\s*(\\d+)\\s*;";
    const char* change = "$1 += $2";                                            //створення шаблону для зміни рядка

    std::regex re(pattern);
    std::string new_str = std::regex_replace(std::string(line), re, change);    //зміна рядка

    
    char* result = new char[LEN];                                               // виділяємо пам'ять для нового рядка
    strncpy_s(result, sizeof(result) / sizeof(result[0]), new_str.c_str(), new_str.size());      //копіюємо результат в масив result
    result[LEN - 1] = '\0';                                                     // додаємо нуль-термінатор 

    return result;
}

void p_operat(const char* fname, const char* fnew)
{
    string pattern = "(\\w+)\\s*=\\s*\\1\\s*\\+\\s*(\\d+)\\s*;";
    string change = "$1 += $2;";
    char line[MAX_LINE_LEN];

    FILE* input_file;
    fopen_s(&input_file, fname, "r");
    if (input_file == NULL) {
        cout << "Error" << endl;
    }

    FILE* output_file;
    fopen_s(&output_file, fnew, "w");
    if (output_file == NULL) {
        cout << "Error" << endl;
    }

    char* new_str = nullptr;                                                // тут будуть зберігатися змінені оператори
    char* last_line = nullptr;                                              // тут буде зберігатися останній змінений оператор з count
    int count = 0;

    while (fgets(line, MAX_LINE_LEN, input_file) != NULL) {                //зчитування по рядках, а не посимвольно
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {                            //перевірка на символи нового рядка
            line[len - 1] = '\0';
            len--;
        }

        smatch match;
        if (find_operators(line, match)) {
            new_str = replace_operators(line);                              //зміна оператора присвоєння
            count++;
            if (last_line != nullptr) {
                delete[] last_line;                                      
            }
            string last_line_str(line);
            last_line_str = regex_replace(new_str, std::regex("\\d+"), std::to_string(count));
            last_line = new char[last_line_str.length() + 1];
            strcpy_s(last_line, last_line_str.length() + 1, last_line_str.c_str());          //копіює з  last_line_str у масив  last_line
            fprintf(output_file, "%s\n", new_str);
        }
        else {
            fprintf(output_file, "%s\n", line);
        }

        delete[] new_str;
        new_str = nullptr;
    }

     if (count > 0) {
         if (last_line != nullptr) {                                                //перевіряє, чи було знайдено останній рядок з відповідними операторами
             string last_line_str(last_line);
             last_line_str = regex_replace(last_line_str, std::regex("\\d+"), std::to_string(count));   //заміняємо число на кількість змінених операторів
             delete[] last_line;                                                    //звільняємо пам'ять
             last_line = new char[last_line_str.length() + 1];                      //виділяємо нову пам'ять для зміненого рядка
             strcpy_s(last_line, (last_line_str.length()+1), (last_line_str.c_str()));    //копіює змінений рядок у масив char *last_line
         }
         else {
             last_line = new char[1];
             last_line[0] = '\0';
         }
         long pos = ftell(output_file) - strlen(line);                              //встановлює позицію курсора в файлі на початок останнього рядка
         fseek(output_file, pos, SEEK_SET);                                         //переміщує курсор файлу на позицію pos
         fprintf(output_file, "\n%s\n", last_line);                                   //запис зміненого рядка
         delete[] last_line;                                                        //звільняє пам'ять
     }

        std::fclose(input_file);
        std::fclose(output_file);
}


void switch_pointer(int ch, const char* fname, const char* fnew)
{
    switch (ch)
    {
    case 1:
        p_read_data(fname);
        break;
    case 2:
        cout << "\n\tINPUT FILE\n" << endl;
        p_read_data(fname);
        cout << "\n\tOUTPUT FILE\n" << endl;
        p_operat(fname, fnew);
        //p_create(fnew);
        p_read_data(fnew);
        break;
    case 3:   
        p_app_data(fname);
        break;
    case 4:
        p_write_data(fname);
        break;
    case 5:
        p_delete(fname);
        break;
    case 0:
        break;
    default:
        break;
    }
}
