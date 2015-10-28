[
    [
        "program", 
        "��������� ����", 
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
                    "����������� ������"
                ], 
                [
                    "int", 
                    "pop_size", 
                    "100", 
                    "������ ���������"
                ], 
                [
                    "int", 
                    "generations", 
                    "100", 
                    "����� ��������"
                ]
            ], 
            "id": "default", 
            "title": "��������� ������"
        }
    ], 
    [
        "better", 
        "����� ������ ��������", 
        {
            "details": "// ����� ��������� ������� �������", 
            "contains": [], 
            "id": "max", 
            "title": "������������"
        }, 
        {
            "details": "// ����� �������� ������� �������", 
            "contains": [], 
            "id": "min", 
            "title": "�����������"
        }
    ], 
    [
        "encoding", 
        "��� �����������", 
        {
            "vars": {
                "gtype": "int"
            }, 
            "title": "�������� �����������", 
            "contains": [], 
            "switches": [
                "ENCODING_BOOL"
            ], 
            "details": "// ����������� ������� ��������� ��������������������", 
            "id": "bool"
        }, 
        {
            "vars": {
                "gtype": "int"
            }, 
            "title": "������������� �����������", 
            "contains": [], 
            "switches": [
                "ENCODING_INT"
            ], 
            "params": [
                [
                    "int", 
                    "min_value", 
                    "0", 
                    "�������"
                ], 
                [
                    "int", 
                    "max_value", 
                    "1", 
                    "��������"
                ]
            ], 
            "details": "// ����������� ������� �������������� ��������������������", 
            "id": "int"
        }, 
        {
            "vars": {
                "gtype": "double"
            }, 
            "title": "�������������������� �����������", 
            "contains": [], 
            "switches": [
                "ENCODING_REAL"
            ], 
            "params": [
                [
                    "double", 
                    "min_value", 
                    "-10.0", 
                    "�������"
                ], 
                [
                    "double", 
                    "max_value", 
                    "10.0", 
                    "��������"
                ]
            ], 
            "details": "// ����������� ������� �������������������� �������������� �����", 
            "id": "real"
        }
    ], 
    [
        "algorithm", 
        "��� ���������", 
        {
            "details": "// ����������� ������ ������������� ���������", 
            "contains": [
                "selectpopulation", 
                "crossoverpopulation", 
                "mutatepopulation", 
                "printpopulation"
            ], 
            "id": "ga", 
            "title": "������������ ��������"
        }, 
        {
            "title": "����� ��� ������", 
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
                    "����������� ������������� �����"
                ], 
                [
                    "double", 
                    "v0", 
                    "1.0", 
                    "������������ ��������� �������� �������� ������"
                ], 
                [
                    "double", 
                    "tau", 
                    "1.0", 
                    "��� �������"
                ]
            ], 
            "details": "// ����������� ������ ������ ��� ������", 
            "id": "psoa", 
            "types": [
                [
                    "double", 
                    "p", 
                    "array", 
                    "������ ����� ��������� �������"
                ], 
                [
                    "double", 
                    "v", 
                    "array", 
                    "������ �������� �������"
                ]
            ]
        }
    ], 
    [
        "selectpopulation", 
        "����� ������", 
        {
            "details": "// ��������� ����� ������", 
            "depends": {
                "algorithm": [
                    "ga"
                ]
            }, 
            "contains": [
                "select"
            ], 
            "id": "tournament", 
            "title": "��������� ����� ������"
        }
    ], 
    [
        "select", 
        "�������� ������", 
        {
            "details": "// ��������� ����� ������", 
            "contains": [], 
            "id": "tournement", 
            "title": "��������� ����� ������"
        }
    ], 
    [
        "crossoverpopulation", 
        "����� �����������", 
        {
            "title": "����� ����������� �� ������ ������������� ���������", 
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
                    "����������� ���������� ����������� � �������� ����"
                ]
            ], 
            "details": "// ����� ����������� �� ������ ������������� ���������", 
            "id": "shuffling"
        }
    ], 
    [
        "crossover", 
        "�������� �����������", 
        {
            "details": "// ������������ �����������", 
            "contains": [], 
            "id": "doublepoint", 
            "title": "������������ �����������"
        }, 
        {
            "details": "// ������������ �����������", 
            "contains": [], 
            "id": "singlepoint", 
            "title": "������������ �����������"
        }, 
        {
            "details": "// ����������� �����������", 
            "contains": [], 
            "params": [
                [
                    "double", 
                    "p_swap", 
                    "0.1", 
                    "����������� ������ ���������� ��������� ���� �����"
                ]
            ], 
            "id": "uniform", 
            "title": "����������� �����������"
        }
    ], 
    [
        "mutatepopulation", 
        "����� �������", 
        {
            "details": "// ����������� ����� �������", 
            "contains": [
                "mutate"
            ], 
            "params": [
                [
                    "double", 
                    "p_mut", 
                    "0.1", 
                    "����������� ������� ��������� �������"
                ]
            ], 
            "id": "default", 
            "title": "����������� ����� �������"
        }
    ], 
    [
        "mutate", 
        "�������� �������", 
        {
            "title": "�������� �������", 
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
                    "����������� ������� ������ ����"
                ]
            ], 
            "details": "// ��������� �������� ������� ���� �������� ������������������ \n// � ������������ p_mutate_rate.", 
            "id": "bool"
        }, 
        {
            "title": "������������� �������", 
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
                    "����������� ������� ������ ����"
                ]
            ], 
            "details": "// ������ ������� ����� �������� ������������������ ��������� ������ �� ��������� ���������. \n// ����������� � ������������ p_mutate_rate.", 
            "id": "intglobal"
        }, 
        {
            "title": "������������� ��������� �������", 
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
                    "����������� ������� ���������� ���� "
                ], 
                [
                    "int", 
                    "mutate_variance", 
                    "1", 
                    "������������ ��������� ������ ����"
                ]
            ], 
            "details": "// ������ ������� ����� �������� ������������������ ��������� �������� ������. \n// ����������� � ������������ p_mutate_rate.", 
            "id": "intlocal"
        }, 
        {
            "title": "�������������������� �������", 
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
                    "����������� ������� ������ ����"
                ]
            ], 
            "details": "// ������ ������� ����� �������� ������������������ ��������� ������ �� ��������� ���������. \n// ����������� � ������������ p_mutate_rate.", 
            "id": "realglobal"
        }, 
        {
            "title": "�������������������� ��������� �������", 
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
                    "����������� ������� ���������� ���� "
                ], 
                [
                    "double", 
                    "mutate_variance", 
                    "0.1", 
                    "������������ ��������� ������ ����"
                ]
            ], 
            "details": "// ������ ������� ����� �������� ������������������ ��������� ������ �� ��������� �����������. \n// ����������� � ������������ p_mutate_rate.", 
            "id": "reallocal"
        }
    ], 
    [
        "getalphabeta", 
        "����� ���������� ���������� ��������", 
        {
            "details": "// ������������� ��������� ���������� ��������", 
            "contains": [], 
            "params": [
                [
                    "double", 
                    "alpha", 
                    "0.5", 
                    "// ����� "
                ], 
                [
                    "double", 
                    "beta", 
                    "0.5", 
                    " // ����"
                ]
            ], 
            "id": "fixed", 
            "title": "������������� ��������� ���������� ��������"
        }
    ], 
    [
        "printpopulation", 
        "������ ���������", 
        {
            "title": "������ ������ � ���������", 
            "contains": [], 
            "params": [
                [
                    "bool", 
                    "printpopulation", 
                    "0", 
                    "������ ���� ���������"
                ], 
                [
                    "bool", 
                    "printbestsolution", 
                    "1", 
                    "������ ������� �������"
                ], 
                [
                    "bool", 
                    "printstatistics", 
                    "1", 
                    "������ �������� � ������� �������� ������� �������"
                ]
            ], 
            "details": "// ������ ������ � ������� ���������: ��� �������, ������ �������, ����������", 
            "include": [
                "<iostream>"
            ], 
            "id": "default"
        }
    ]
]
