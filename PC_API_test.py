import minList
import Python_Source

tests = [10_000_000, 100_000_000, 250_000_000]

for k_el in tests:
    l = [_ for _ in range(1, k_el+1)] [::-1]

    result_C = minList.minel(l)
    result_Python = Python_Source.minList(l)

    print('-'*50)
    print(f'Время выполнения на C: ({k_el} элементов в списке)\n')
    print(f'Минимальный элемент в списке = {result_C[0]}')
    print(f'Время выполнения - {round( result_C[1], 2 )} сек')

    print('-'*50)

    print(f'Время выполнения на Python: ({k_el} элементов в списке)\n')
    print(f'Минимальный элемент в списке = {result_Python[0]}')
    print(f'Время выполнения - {round( result_Python[1], 2 )} сек')