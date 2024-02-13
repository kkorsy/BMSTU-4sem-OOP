template <typename T>
class Holder
{
    T* ptr{nullptr}; // Указатель на объект (сразу же его обнуляем)
    
    public:
        explicit Holder(T *p) : ptr(p) {}; // Захватываем указатель и запрещаем неявный вызов конструктора
        ~Holder() {delete ptr;}            // Задача деструктора - удалить объект
        
        // Определяем джентельменский набор из трёх операторов
        T& operator *() const {return *ptr;}
        T* operator ->() const {return ptr;}
        operator bool() const { return ptr != nullptr; }
        
        // Запрещаем конструктор копирования и оператор присваивания
        Holder(const Holder &) = delete; // Если у нас параметр T по умолчанию, можно его явно не указвать
                                        // а использовать & (просто пояснение)
        Holder operator=(const Holder &) = delete; 
};