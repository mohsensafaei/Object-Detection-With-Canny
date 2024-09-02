#pragma once

#include <stdio.h>
#include <string.h>

/*Original Colors*/
#define RESET      "\033[0;0m"
#define RED        "\033[31m"          
#define GREEN      "\033[32m"
#define BLUE       "\033[0;34m"           
#define YELLOW     "\033[33m"         
#define PURPLE     "\033[0;35m"          
#define ORANGE     "\033[38;5;208m"

/*Bold Colors*/
#define BOLD_RED   "\033[1;31m"       
#define BOLD_WHITE "\033[1;37m"        
#define BOLD_YELLOW "\033[1;33m"       
#define BOLD_GREEN "\033[1;32m"       
#define BOLD_ORANGE "\033[1;38;5;208m"
#define BOLD_BLUE "\033[1;34m"

#define HARSH_RED "\033[1;38;5;196m"

const char* extractFileName(const char* filePath);

#define _INFO_ BOLD_WHITE "[%s]" " INFO" " (LINE: %d) " PURPLE " ==> "
#define _WARN_ BOLD_WHITE "[%s] " BOLD_YELLOW "WARN" BOLD_WHITE " (LINE: %d) " PURPLE " ==> "
#define _ERROR_ BOLD_WHITE "[%s] " BOLD_RED  "ERROR" BOLD_WHITE " (LINE: %d) " PURPLE " ==> "
#define _TIME_ BOLD_WHITE "[%s] " BOLD_BLUE  "TIME" BOLD_WHITE " (LINE: %d) " PURPLE " ==> "
#define _SUCCESS_ BOLD_WHITE "[%s] " BOLD_GREEN "SUCCESS" BOLD_WHITE " (LINE: %d) " PURPLE " ==> "
#define _FAIL_ BOLD_WHITE "[%s] " HARSH_RED "FAIL" BOLD_WHITE " (LINE: %d) " PURPLE " ==> "
#define _LOAD_ BOLD_WHITE "[%s] " BOLD_ORANGE "LOADING" BOLD_WHITE " (LINE: %d) " PURPLE " ==> "

#define INFO_LOG(fmt, ...) fprintf(stdout, _INFO_ RESET fmt "\n", extractFileName(__FILE__), __LINE__, ##__VA_ARGS__)
#define WARN_LOG(fmt, ...) fprintf(stdout, _WARN_ RESET fmt "\n",extractFileName(__FILE__), __LINE__, ##__VA_ARGS__)
#define ERROR_LOG(fmt, ...) fprintf(stdout, _ERROR_ RESET fmt "\n",extractFileName(__FILE__), __LINE__, ##__VA_ARGS__)
#define TIME_LOG(fmt, ...) fprintf(stdout, _TIME_ RESET fmt "\n",extractFileName(__FILE__), __LINE__,##__VA_ARGS__)
#define RESULT_SUCCESS_LOG(fmt, ...) fprintf(stdout, _SUCCESS_ RESET fmt "\n",extractFileName(__FILE__),__LINE__, ##__VA_ARGS__)
#define RESULT_FAIL_LOG(fmt, ...) fprintf(stdout, _FAIL_ RESET fmt "\n",extractFileName(__FILE__),__LINE__, ##__VA_ARGS__)
#define LOADING_LOG(fmt, ...) fprintf(stdout, _LOAD_ RESET fmt "\n",extractFileName(__FILE__),__LINE__, ##__VA_ARGS__)

#pragma once
