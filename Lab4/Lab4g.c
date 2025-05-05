#include <stdio.h>
#include <stdlib.h>

int part_g_h()
{
    char *env_value = getenv("MY_ENV_VAR");
    if (env_value == NULL)
    {
        perror("Ошибка при получении переменной окружения");
        return 1;
    }
    printf("MY_ENV_VAR = %s\n", env_value);

    int result = setenv("MY_ENV_VAR", "modified_in_process", 1);
    if (result == -1)
    {
        perror("Ошибка при изменении переменной окружения");
        return 1;
    }

    env_value = getenv("MY_ENV_VAR");
    if (env_value == NULL)
    {
        perror("Ошибка при повторном получении переменной окружения");
        return 1;
    }
    printf("MY_ENV_VAR (после изменения) = %s\n", env_value);

    return 0;
}

int main(void)
{
    int return_code = part_g_h();

    return return_code;
}
