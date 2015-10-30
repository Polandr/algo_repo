{
    "body": [
        {
            "body": [
                {
                    "val": "10", 
                    "type": "int", 
                    "name": "task_dim", 
                    "key": "PARAMETER", 
                    "details": "Размерность задачи"
                }, 
                {
                    "val": "33", 
                    "type": "int", 
                    "name": "pop_size", 
                    "key": "PARAMETER", 
                    "details": "Размер популяции"
                }, 
                {
                    "val": "199", 
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
                    "key": "ENCODING_BOOL"
                }, 
                {
                    "val": "0.5", 
                    "type": "double", 
                    "name": "p_cross", 
                    "key": "PARAMETER", 
                    "details": "вероятность выполнения скрещивания в заданной паре"
                }, 
                {
                    "val": "0.2", 
                    "type": "double", 
                    "name": "p_swap", 
                    "key": "PARAMETER", 
                    "details": "вероятность обмена значениями выбранной пары генов"
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
                    "details": "Вероятность мутации одного гена"
                }, 
                {
                    "val": "0", 
                    "type": "bool", 
                    "name": "printpopulation", 
                    "key": "PARAMETER", 
                    "details": "печать всей популяции"
                }, 
                {
                    "val": "0", 
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
            "encoding": "bool", 
            "getalphabeta": "", 
            "better_details": "// Поиск максимума целевой функции", 
            "crossoverpopulation": "shuffling", 
            "crossover": "uniform", 
            "selectpopulation_details": "// Турнирная схема отбора", 
            "select": "tournement", 
            "select_details": "// Турнирная схема отбора", 
            "selectpopulation": "tournament", 
            "crossoverpopulation_details": "// Схема скрещивания на основе перемешивания популяции", 
            "better": "max", 
            "program": "default", 
            "mutate_details": "// Случайная инверсия каждого бита заданной последовательности \n// с вероятностью p_mutate_rate.", 
            "mutate": "bool", 
            "mutatepopulation": "default", 
            "encoding_details": "// Кодирование решений двоичными последовательностями", 
            "key": "GLOBAL", 
            "printpopulation": "default", 
            "crossover_details": "// Равномерное скрещивание", 
            "algorithm": "ga", 
            "mutatepopulation_details": "// Стандартная схема мутации", 
            "printpopulation_details": "// Печать данных о текущей популяции: все решения, лучшее решение, статистика", 
            "algorithm_details": "// Стандартная версия генетического алгоритма", 
            "gtype": "int"
        }
    ]
}
