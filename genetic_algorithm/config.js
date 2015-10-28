{
    "body": [
        {
            "body": [
                {
                    "val": "5", 
                    "type": "int", 
                    "name": "task_dim", 
                    "key": "PARAMETER", 
                    "details": "Размерность задачи"
                }, 
                {
                    "val": "10", 
                    "type": "int", 
                    "name": "pop_size", 
                    "key": "PARAMETER", 
                    "details": "Размер популяции"
                }, 
                {
                    "val": "1000", 
                    "type": "int", 
                    "name": "generations", 
                    "key": "PARAMETER", 
                    "details": "Число итераций"
                }, 
                {
                    "header": "\"stdafx.h\"", 
                    "key": "INCLUDE"
                }, 
                {
                    "val": "0", 
                    "type": "int", 
                    "name": "min_value", 
                    "key": "PARAMETER", 
                    "details": "минимум"
                }, 
                {
                    "val": "10", 
                    "type": "int", 
                    "name": "max_value", 
                    "key": "PARAMETER", 
                    "details": "максимум"
                }, 
                {
                    "key": "ENCODING_INT"
                }, 
                {
                    "val": "0.5", 
                    "type": "double", 
                    "name": "p_cross", 
                    "key": "PARAMETER", 
                    "details": "вероятность выполнения скрещивания в заданной паре"
                }, 
                {
                    "val": "0.1", 
                    "type": "double", 
                    "name": "p_mut", 
                    "key": "PARAMETER", 
                    "details": "вероятность мутации заданного решения"
                }, 
                {
                    "val": "0.01", 
                    "type": "double", 
                    "name": "p_mutation_rate", 
                    "key": "PARAMETER", 
                    "details": "Вероятность мутации отдельного гена "
                }, 
                {
                    "val": "1", 
                    "type": "int", 
                    "name": "mutate_variance", 
                    "key": "PARAMETER", 
                    "details": "Максимальное изменение одного гена"
                }, 
                {
                    "val": "0", 
                    "type": "bool", 
                    "name": "printpopulation", 
                    "key": "PARAMETER", 
                    "details": "печать всей популяции"
                }, 
                {
                    "val": "1", 
                    "type": "bool", 
                    "name": "printbestsolution", 
                    "key": "PARAMETER", 
                    "details": "печать лучшего решения"
                }, 
                {
                    "val": "1", 
                    "type": "bool", 
                    "name": "printstatistics", 
                    "key": "PARAMETER", 
                    "details": "печать среднего и лучшего значений целевой функции"
                }, 
                {
                    "header": "<iostream>", 
                    "key": "INCLUDE"
                }
            ], 
            "program_details": "", 
            "encoding": "int", 
            "getalphabeta": "", 
            "better_details": "// Поиск минимума целевой функции", 
            "crossoverpopulation": "shuffling", 
            "crossover": "doublepoint", 
            "selectpopulation_details": "// Турнирная схема отбора", 
            "select": "tournement", 
            "select_details": "// Турнирная схема отбора", 
            "selectpopulation": "tournament", 
            "crossoverpopulation_details": "// Схема скрещивания на основе перемешивания популяции", 
            "better": "min", 
            "program": "default", 
            "mutate_details": "// Замена каждого числа заданной последовательности случайным соседним числом. \n// Выполняется с вероятностью p_mutate_rate.", 
            "mutate": "intlocal", 
            "mutatepopulation": "default", 
            "encoding_details": "// Кодирование решений целочисленными последовательностями", 
            "key": "GLOBAL", 
            "printpopulation": "default", 
            "crossover_details": "// Двухточечное скрещивание", 
            "algorithm": "ga", 
            "mutatepopulation_details": "// Стандартная схема мутации", 
            "printpopulation_details": "// Печать данных о текущей популяции: все решения, лучшее решение, статистика", 
            "algorithm_details": "// Стандартная версия генетического алгоритма", 
            "gtype": "int"
        }
    ]
}
