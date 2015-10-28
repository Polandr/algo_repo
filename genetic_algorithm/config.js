{
    "body": [
        {
            "body": [
                {
                    "val": "5", 
                    "type": "int", 
                    "name": "task_dim", 
                    "key": "PARAMETER", 
                    "details": "����������� ������"
                }, 
                {
                    "val": "10", 
                    "type": "int", 
                    "name": "pop_size", 
                    "key": "PARAMETER", 
                    "details": "������ ���������"
                }, 
                {
                    "val": "1000", 
                    "type": "int", 
                    "name": "generations", 
                    "key": "PARAMETER", 
                    "details": "����� ��������"
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
                    "details": "�������"
                }, 
                {
                    "val": "10", 
                    "type": "int", 
                    "name": "max_value", 
                    "key": "PARAMETER", 
                    "details": "��������"
                }, 
                {
                    "key": "ENCODING_INT"
                }, 
                {
                    "val": "0.5", 
                    "type": "double", 
                    "name": "p_cross", 
                    "key": "PARAMETER", 
                    "details": "����������� ���������� ����������� � �������� ����"
                }, 
                {
                    "val": "0.1", 
                    "type": "double", 
                    "name": "p_mut", 
                    "key": "PARAMETER", 
                    "details": "����������� ������� ��������� �������"
                }, 
                {
                    "val": "0.01", 
                    "type": "double", 
                    "name": "p_mutation_rate", 
                    "key": "PARAMETER", 
                    "details": "����������� ������� ���������� ���� "
                }, 
                {
                    "val": "1", 
                    "type": "int", 
                    "name": "mutate_variance", 
                    "key": "PARAMETER", 
                    "details": "������������ ��������� ������ ����"
                }, 
                {
                    "val": "0", 
                    "type": "bool", 
                    "name": "printpopulation", 
                    "key": "PARAMETER", 
                    "details": "������ ���� ���������"
                }, 
                {
                    "val": "1", 
                    "type": "bool", 
                    "name": "printbestsolution", 
                    "key": "PARAMETER", 
                    "details": "������ ������� �������"
                }, 
                {
                    "val": "1", 
                    "type": "bool", 
                    "name": "printstatistics", 
                    "key": "PARAMETER", 
                    "details": "������ �������� � ������� �������� ������� �������"
                }, 
                {
                    "header": "<iostream>", 
                    "key": "INCLUDE"
                }
            ], 
            "program_details": "", 
            "encoding": "int", 
            "getalphabeta": "", 
            "better_details": "// ����� �������� ������� �������", 
            "crossoverpopulation": "shuffling", 
            "crossover": "doublepoint", 
            "selectpopulation_details": "// ��������� ����� ������", 
            "select": "tournement", 
            "select_details": "// ��������� ����� ������", 
            "selectpopulation": "tournament", 
            "crossoverpopulation_details": "// ����� ����������� �� ������ ������������� ���������", 
            "better": "min", 
            "program": "default", 
            "mutate_details": "// ������ ������� ����� �������� ������������������ ��������� �������� ������. \n// ����������� � ������������ p_mutate_rate.", 
            "mutate": "intlocal", 
            "mutatepopulation": "default", 
            "encoding_details": "// ����������� ������� �������������� ��������������������", 
            "key": "GLOBAL", 
            "printpopulation": "default", 
            "crossover_details": "// ������������ �����������", 
            "algorithm": "ga", 
            "mutatepopulation_details": "// ����������� ����� �������", 
            "printpopulation_details": "// ������ ������ � ������� ���������: ��� �������, ������ �������, ����������", 
            "algorithm_details": "// ����������� ������ ������������� ���������", 
            "gtype": "int"
        }
    ]
}
