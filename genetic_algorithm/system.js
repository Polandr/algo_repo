[
    [
        "program", 
        "Начальный слот", 
        {
            "include": [
                "\"stdafx.h\""
            ], 
            "contains": [
                "better", 
                "encoding", 
                "algorithm"
            ], 
            "params": [
                [
                    "int", 
                    "task_dim", 
                    "10", 
                    "Размерность задачи"
                ], 
                [
                    "int", 
                    "pop_size", 
                    "100", 
                    "Размер популяции"
                ], 
                [
                    "int", 
                    "generations", 
                    "100", 
                    "Число итераций"
                ]
            ], 
            "id": "default", 
            "title": "Начальный шаблон"
        }
    ], 
    [
        "better", 
        "Какая задача решается", 
        {
            "details": "// Поиск максимума целевой функции", 
            "contains": [], 
            "id": "max", 
            "title": "Максимизация"
        }, 
        {
            "details": "// Поиск минимума целевой функции", 
            "contains": [], 
            "id": "min", 
            "title": "Минимизация"
        }
    ], 
    [
        "encoding", 
        "Тип кодирования", 
        {
            "vars": {
                "gtype": "int"
            }, 
            "title": "Двоичное кодирование", 
            "contains": [], 
            "switches": [
                "ENCODING_BOOL"
            ], 
            "details": "// Кодирование решений двоичными последовательностями", 
            "id": "bool"
        }, 
        {
            "vars": {
                "gtype": "int"
            }, 
            "title": "Целочисленное кодирование", 
            "contains": [], 
            "switches": [
                "ENCODING_INT"
            ], 
            "params": [
                [
                    "int", 
                    "min_value", 
                    "0", 
                    "минимум"
                ], 
                [
                    "int", 
                    "max_value", 
                    "1", 
                    "максимум"
                ]
            ], 
            "details": "// Кодирование решений целочисленными последовательностями", 
            "id": "int"
        }, 
        {
            "vars": {
                "gtype": "double"
            }, 
            "title": "Действительнозначное кодирование", 
            "contains": [], 
            "switches": [
                "ENCODING_REAL"
            ], 
            "params": [
                [
                    "double", 
                    "min_value", 
                    "-10.0", 
                    "минимум"
                ], 
                [
                    "double", 
                    "max_value", 
                    "10.0", 
                    "максимум"
                ]
            ], 
            "details": "// Кодирование решений последовательностями действительных чисел", 
            "id": "real"
        }
    ], 
    [
        "algorithm", 
        "Тип алгоритма", 
        {
            "details": "// Стандартная версия генетического алгоритма", 
            "contains": [
                "selectpopulation", 
                "crossoverpopulation", 
                "mutatepopulation", 
                "printpopulation"
            ], 
            "id": "ga", 
            "title": "Генетический алгоритм"
        }, 
        {
            "title": "Метод роя частиц", 
            "contains": [
                "getalphabeta", 
                "printpopulation"
            ], 
            "depends": {
                "encoding": [
                    "real"
                ]
            }, 
            "params": [
                [
                    "double", 
                    "eta", 
                    "0.9", 
                    "коэффициент сопротивления среды"
                ], 
                [
                    "double", 
                    "v0", 
                    "1.0", 
                    "максимальное начальное значение скорости частиц"
                ], 
                [
                    "double", 
                    "tau", 
                    "1.0", 
                    "шаг времени"
                ]
            ], 
            "details": "// Стандартная версия метода роя частиц", 
            "id": "psoa", 
            "types": [
                [
                    "double", 
                    "p", 
                    "array", 
                    "лучшая точка трактории частицы"
                ], 
                [
                    "double", 
                    "v", 
                    "array", 
                    "вектор скорости частицы"
                ]
            ]
        }
    ], 
    [
        "selectpopulation", 
        "Схема отбора", 
        {
            "details": "// Турнирная схема отбора", 
            "depends": {
                "algorithm": [
                    "ga"
                ]
            }, 
            "contains": [
                "select"
            ], 
            "id": "tournament", 
            "title": "Турнирная схема отбора"
        }
    ], 
    [
        "select", 
        "Оператор отбора", 
        {
            "details": "// Турнирная схема отбора", 
            "contains": [], 
            "id": "tournement", 
            "title": "Турнирная схема отбора"
        }
    ], 
    [
        "crossoverpopulation", 
        "Схема скрещивания", 
        {
            "title": "Схема скрещивания на основе перемешивания популяции", 
            "contains": [
                "crossover"
            ], 
            "depends": {
                "algorithm": [
                    "ga"
                ]
            }, 
            "params": [
                [
                    "double", 
                    "p_cross", 
                    "0.5", 
                    "вероятность выполнения скрещивания в заданной паре"
                ]
            ], 
            "details": "// Схема скрещивания на основе перемешивания популяции", 
            "id": "shuffling"
        }
    ], 
    [
        "crossover", 
        "Оператор скрещивания", 
        {
            "details": "// Двухточечное скрещивание", 
            "contains": [], 
            "id": "doublepoint", 
            "title": "Двухточечное скрещивание"
        }, 
        {
            "details": "// Одноточечное скрещивание", 
            "contains": [], 
            "id": "singlepoint", 
            "title": "Одноточечное скрещивание"
        }, 
        {
            "details": "// Равномерное скрещивание", 
            "contains": [], 
            "params": [
                [
                    "double", 
                    "p_swap", 
                    "0.1", 
                    "вероятность обмена значениями выбранной пары генов"
                ]
            ], 
            "id": "uniform", 
            "title": "Равномерное скрещивание"
        }
    ], 
    [
        "mutatepopulation", 
        "Схема мутации", 
        {
            "details": "// Стандартная схема мутации", 
            "contains": [
                "mutate"
            ], 
            "params": [
                [
                    "double", 
                    "p_mut", 
                    "0.1", 
                    "вероятность мутации заданного решения"
                ]
            ], 
            "id": "default", 
            "title": "Стандартная схема мутации"
        }
    ], 
    [
        "mutate", 
        "Оператор мутации", 
        {
            "title": "Двоичная мутация", 
            "contains": [], 
            "depends": {
                "encoding": [
                    "bool"
                ]
            }, 
            "params": [
                [
                    "double", 
                    "p_mutation_rate", 
                    "0.01", 
                    "Вероятность мутации одного гена"
                ]
            ], 
            "details": "// Случайная инверсия каждого бита заданной последовательности \n// с вероятностью p_mutate_rate.", 
            "id": "bool"
        }, 
        {
            "title": "Целочисленная мутация", 
            "contains": [], 
            "depends": {
                "encoding": [
                    "int"
                ]
            }, 
            "params": [
                [
                    "double", 
                    "p_mutation_rate", 
                    "0.01", 
                    "Вероятность мутации одного гена"
                ]
            ], 
            "details": "// Замена каждого числа заданной последовательности случайным числом из заданного диапазона. \n// Выполняется с вероятностью p_mutate_rate.", 
            "id": "intglobal"
        }, 
        {
            "title": "Целочисленная локальная мутация", 
            "contains": [], 
            "depends": {
                "encoding": [
                    "int"
                ]
            }, 
            "params": [
                [
                    "double", 
                    "p_mutation_rate", 
                    "0.01", 
                    "Вероятность мутации отдельного гена "
                ], 
                [
                    "int", 
                    "mutate_variance", 
                    "1", 
                    "Максимальное изменение одного гена"
                ]
            ], 
            "details": "// Замена каждого числа заданной последовательности случайным соседним числом. \n// Выполняется с вероятностью p_mutate_rate.", 
            "id": "intlocal"
        }, 
        {
            "title": "Действительнозначная мутация", 
            "contains": [], 
            "depends": {
                "encoding": [
                    "real"
                ]
            }, 
            "params": [
                [
                    "double", 
                    "p_mutation_rate", 
                    "0.01", 
                    "Вероятность мутации одного гена"
                ]
            ], 
            "details": "// Замена каждого числа заданной последовательности случайным числом из заданного диапазона. \n// Выполняется с вероятностью p_mutate_rate.", 
            "id": "realglobal"
        }, 
        {
            "title": "Действительнозначная локальная мутация", 
            "contains": [], 
            "depends": {
                "encoding": [
                    "real"
                ]
            }, 
            "params": [
                [
                    "double", 
                    "p_mutation_rate", 
                    "0.01", 
                    "Вероятность мутации отдельного гена "
                ], 
                [
                    "double", 
                    "mutate_variance", 
                    "0.1", 
                    "Максимальное изменение одного гена"
                ]
            ], 
            "details": "// Замена каждого числа заданной последовательности случайным числом из локальной окрестности. \n// Выполняется с вероятностью p_mutate_rate.", 
            "id": "reallocal"
        }
    ], 
    [
        "getalphabeta", 
        "Выбор параметров обновление скорости", 
        {
            "details": "// Фиксированные параметры обновления скорости", 
            "contains": [], 
            "params": [
                [
                    "double", 
                    "alpha", 
                    "0.5", 
                    "// альфа "
                ], 
                [
                    "double", 
                    "beta", 
                    "0.5", 
                    " // бета"
                ]
            ], 
            "id": "fixed", 
            "title": "Фиксированные параметры обновления скорости"
        }
    ], 
    [
        "printpopulation", 
        "Печать популяции", 
        {
            "title": "Печать данных о популяции", 
            "contains": [], 
            "params": [
                [
                    "bool", 
                    "printpopulation", 
                    "0", 
                    "печать всей популяции"
                ], 
                [
                    "bool", 
                    "printbestsolution", 
                    "1", 
                    "печать лучшего решения"
                ], 
                [
                    "bool", 
                    "printstatistics", 
                    "1", 
                    "печать среднего и лучшего значений целевой функции"
                ]
            ], 
            "details": "// Печать данных о текущей популяции: все решения, лучшее решение, статистика", 
            "include": [
                "<iostream>"
            ], 
            "id": "default"
        }
    ]
]
