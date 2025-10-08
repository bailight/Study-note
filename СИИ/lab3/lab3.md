лаб3
1. пишем класс модели SVM
2. в классе должны быть методы

def __init__(...): 
#some code
def predict(...): 
#some code
def fit(...): 
#some code

и все остальное, что вам необходимо
Фит делаем по батчам

3. берем датасет (решаем только задачу классификации). Датасет тяжелый, около 9 гигов.

import moabb.datasets

m_dataset = moabb.datasets.bi2013a(
    NonAdaptive=True,
    Adaptive=True,
    Training=True,
    Online=True,
)

m_dataset.download()
4. предобрабатываем датасет
5. обучаем модель
6. выводим метрики качества (ошибки, точность предсказаний, etc.)