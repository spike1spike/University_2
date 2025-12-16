import time

def minList(l: list) -> tuple:
    '''Функция находит минимальный элемент в списке и вычисляет время выполнения операция
    :param l: Исходный список
    :return result: Возвращает массив из минимального элемента и времени выполнения'''

    start_time = time.time()

    length = len(l)
    min_el = l[0]

    for i in range(1, length):
        elem = l[i]
        if elem < min_el:
            min_el = elem
    
    end_time = time.time()
    time_taken = end_time - start_time

    result = (min_el, time_taken)

    return result


__all__ = ['minList']