#include <stdio.h>
#include <stdlib.h>

#include "logger.h"

int main()
{
    printf("Testing Logger module.\n");

    LOGGER* my_logger = factory_create_logger();
    init_logger(my_logger, LOGGER_STDOUT, LOGGER_OVERWRITE);

    enable_logger(my_logger);
    log_info(my_logger, "log test");

    cleanup_logger(my_logger);

    return 0;
}
