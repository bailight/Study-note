
### **Acc32指令集架构（ISA）文档**  
**Документация по architektуры инструкций Acc32 (ISA)**  
Acc32 ISA是一款专为教学目的设计的简单累加器型指令集。本文档概述了Acc32 ISA中可用的指令、语法和语义。  
Acc32 ISA — это простой аккумуляторный набор инструкций, разработанный для учебных целей. Документация предоставляет обзор инструкций, их синтаксис и семантику.  

汇编代码中的注释由`;`字符表示。  
Комментарии в ассемблерном коде обозначаются символом `;`.  


## **ISA特定状态视图**  
### **Виделицы состояния ISA**  
- `Acc:dec`, `Acc:hex` — 累加器寄存器（Acc register）。  
- `Acc:dec`, `Acc:hex` — аккумуляторный регистр (Acc register).  
- `V` — 溢出标志（Overflow flag）。  
- `V` — флаг переполнения (Overflow flag).  
- `C` — 进位标志（Carry flag）。  
- `C` — флаг переноса (Carry flag).  


## **指令**  
### **Инструкции**  
**指令长度**：操作码占1字节，绝对操作数占4字节，相对操作数占2字节。  
**Длина инструкции**: 1 байт для опкода, 4 байта для абсолютного операнда, 2 байта для относительного операнда.  
控制流指令、加载/存储指令（立即数/间接/地址）使用绝对地址，其他指令使用相对地址。  
Контрол_flow, Load/Store Immediate/Indirect/Addr используют абсолютные адреса, другие инструкции — относительные.  


### **数据传输指令**  
### **Инструкции перемещения данных**  
1. **加载立即数**  
   - **语法**：`load_imm <address>`  
   - **描述**：将立即数值加载到累加器中。  
   - **操作**：`acc <- <address>`  
   1. **Load Immediate (Загрузить немедленное значение)**  
      - **Синтаксис**: `load_imm <address>`  
      - **Описание**: Загрузить немедленное значение в аккумулятор.  
      - **Операция**: `acc <- <address>`  

2. **加载**  
   - **语法**：`load <offset>`  
   - **描述**：从相对地址加载值到累加器。  
   - **操作**：`acc <- mem[pc + <offset>]`  
   2. **Load (Загрузить)**  
      - **Синтаксис**: `load <offset>`  
      - **Описание**: Загрузить значение с относительного адреса в аккумулятор.  
      - **Операция**: `acc <- mem[pc + <offset>]`  

3. **存储**  
   - **语法**：`store <offset>`  
   - **描述**：将累加器值存储到相对地址。  
   - **操作**：`mem[pc + <offset>] <- acc`  
   3. **Store (Сохранить)**  
      - **Синтаксис**: `store <offset>`  
      - **Описание**: Сохранить значение аккумулятора в относительный адрес.  
      - **Операция**: `mem[pc + <offset>] <- acc`  

4. **加载地址**  
   - **语法**：`load_addr <address>`  
   - **描述**：从指定地址加载值到累加器。  
   - **操作**：`acc <- mem[<address>]`  
   4. **Load Address (Загрузить адрес)**  
      - **Синтаксис**: `load_addr <address>`  
      - **Описание**: Загрузить значение с конкретного адреса в аккумулятор.  
      - **Операция**: `acc <- mem[<address>]`  

5. **存储地址**  
   - **语法**：`store_addr <address>`  
   - **描述**：将累加器值存储到指定地址。  
   - **操作**：`mem[<address>] <- acc`  
   5. **Store Address (Сохранить по адресу)**  
      - **Синтаксис**: `store_addr <address>`  
      - **Описание**: Сохранить значение аккумулятора в конкретный адрес.  
      - **Операция**: `mem[<address>] <- acc`  

6. **间接加载**  
   - **语法**：`load_ind <address>`  
   - **描述**：从间接地址加载值到累加器（先取地址中的值，再取该值对应的内存值）。  
   - **操作**：`acc <- mem[mem[<address>]]`  
   6. **Load Indirect (Инди.rectная загрузка)**  
      - **Синтаксис**: `load_ind <address>`  
      - **Описание**: Загрузить значение из инди.rectного адреса в аккумулятор (сначала получить адрес из памяти, затем значение по этому адресу).  
      - **Операция**: `acc <- mem[mem[<address>]]`  

7. **间接存储**  
   - **语法**：`store_ind <address>`  
   - **描述**：将累加器值存储到间接地址（先取地址中的值，再存储到该值对应的内存地址）。  
   - **操作**：`mem[mem[<address>]] <- acc`  
   7. **Store Indirect (Инди.rectное хранение)**  
      - **Синтаксис**: `store_ind <address>`  
      - **Описание**: Сохранить значение аккумулятора в инди.rectный адрес (сначала получить адрес из памяти, затем сохранить значение по этому адресу).  
      - **Операция**: `mem[mem[<address>]] <- acc`  


### **算术指令**  
### **Арифметические инструкции**  
1. **加法**  
   - **语法**：`add <address>`  
   - **描述**：将指定地址中的值与累加器相加。  
   - **操作**：`acc <- acc + mem[<address>]`，并设置`C`和`V`标志。  
   1. **Add (Сложение)**  
      - **Синтаксис**: `add <address>`  
      - **Описание**: Сложить значение из конкретного адреса с аккумулятором.  
      - **Операция**: `acc <- acc + mem[<address>]`, установить флаги `C` и `V`.  

2. **减法**  
   - **语法**：`sub <address>`  
   - **描述**：用累加器减去指定地址中的值。  
   - **操作**：`acc <- acc - mem[<address>]`，并设置`V`标志。  
   2. **Subtract (Вычитание)**  
      - **Синтаксис**: `sub <address>`  
      - **Описание**: Вычесть значение из конкретного адреса из аккумулятора.  
      - **Операция**: `acc <- acc - mem[<address>]`, установить флаг `V`.  

3. **乘法**  
   - **语法**：`mul <address>`  
   - **描述**：将累加器与指定地址中的值相乘。  
   - **操作**：`acc <- acc * mem[<address>]`，并设置`V`标志。  
   3. **Multiply (Умножение)**  
      - **Синтаксис**: `mul <address>`  
      - **Описание**: Умножить аккумулятор на значение из конкретного адреса.  
      - **Операция**: `acc <- acc * mem[<address>]`, установить флаг `V`.  

4. **除法**  
   - **语法**：`div <address>`  
   - **描述**：用累加器除以指定地址中的值。  
   - **操作**：`acc <- acc / mem[<address>]`  
   4. **Divide (Деление)**  
      - **Синтаксис**: `div <address>`  
      - **Описание**: Разделить аккумулятор на значение из конкретного адреса.  
      - **Операция**: `acc <- acc / mem[<address>]`  

5. **取余**  
   - **语法**：`rem <address>`  
   - **描述**：计算累加器除以指定地址中值的余数。  
   - **操作**：`acc <- acc % mem[<address>]`  
   5. **Remainder (Остаток)**  
      - **Синтаксис**: `rem <address>`  
      - **Описание**: Вычислить остаток от деления аккумулятора на значение из конкретного адреса.  
      - **Операция**: `acc <- acc % mem[<address>]`  

6. **清除溢出标志**  
   - **语法**：`clv`  
   - **描述**：清除溢出标志`V`。  
   - **操作**：`overflow <- 0`  
   6. **Clear Overflow (Очистить флаг переполнения)**  
      - **Синтаксис**: `clv`  
      - **Описание**: Очистить флаг переполнения `V`.  
      - **Операция**: `overflow <- 0`  


### **位运算指令**  
### **Поразрядные инструкции**  
1. **左移**  
   - **语法**：`shiftl <address>`  
   - **描述**：将累加器左移指定地址中存储的位数（不使用进位标志`C`）。  
   - **操作**：`acc <- acc << mem[<address>]`  
   1. **Shift Left (Сдвиг влево)**  
      - **Синтаксис**: `shiftl <address>`  
      - **Описание**: Сдвинуть аккумулятор влево на количество бит, указанное в конкретном адресе (флаг переноса `C` не используется).  
      - **Операция**: `acc <- acc << mem[<address>]`  

2. **右移**  
   - **语法**：`shiftr <address>`  
   - **描述**：将累加器右移指定地址中存储的位数（不使用进位标志`C`）。  
   - **操作**：`acc <- acc >> mem[<address>]`  
   2. **Shift Right (Сдвиг вправо)**  
      - **Синтаксис**: `shiftr <address>`  
      - **Описание**: Сдвинуть аккумулятор вправо на количество бит, указанное в конкретном адресе (флаг переноса `C` не используется).  
      - **Операция**: `acc <- acc >> mem[<address>]`  

3. **按位与**  
   - **语法**：`and <address>`  
   - **描述**：将累加器与指定地址中的值进行按位与运算。  
   - **操作**：`acc <- acc & mem[<address>]`  
   3. **Bitwise AND (Поразрядное И)**  
      - **Синтаксис**: `and <address>`  
      - **Описание**: Выполнить поразрядное И между аккумулятором и значением из конкретного адреса.  
      - **Операция**: `acc <- acc & mem[<address>]`  

4. **按位或**  
   - **语法**：`or <address>`  
   - **描述**：将累加器与指定地址中的值进行按位或运算。  
   - **操作**：`acc <- acc | mem[<address>]`  
   4. **Bitwise OR (Поразрядное ИЛИ)**  
      - **Синтаксис**: `or <address>`  
      - **Описание**: Выполнить поразрядное ИЛИ между аккумулятором и значением из конкретного адреса.  
      - **Операция**: `acc <- acc | mem[<address>]`  

5. **按位异或**  
   - **语法**：`xor <address>`  
   - **描述**：将累加器与指定地址中的值进行按位异或运算。  
   - **操作**：`acc <- acc ^ mem[<address>]`  
   5. **Bitwise XOR (Поразрядное исключающее ИЛИ)**  
      - **Синтаксис**: `xor <address>`  
      - **Описание**: Выполнить поразрядное исключающее ИЛИ между аккумулятором и значением из конкретного адреса.  
      - **Операция**: `acc <- acc ^ mem[<address>]`  

6. **按位非**  
   - **语法**：`not`  
   - **描述**：对累加器进行按位取反运算。  
   - **操作**：`acc <- ~acc`  
   6. **Bitwise NOT (Поразрядное НЕ)**  
      - **Синтаксис**: `not`  
      - **Описание**: Выполнить поразрядное отрицание аккумулятора.  
      - **Операция**: `acc <- ~acc`  


### **控制流指令**  
### **Инструкции управления ходом программы**  
1. **跳转**  
   - **语法**：`jmp <address>`  
   - **描述**：跳转到指定地址。  
   - **操作**：`pc <- <address>`  
   1. **Jump (Перенос)**  
      - **Синтаксис**: `jmp <address>`  
      - **Описание**: Перейти по конкретному адресу.  
      - **Операция**: `pc <- <address>`  

2. **等于零则分支**  
   - **语法**：`beqz <address>`  
   - **描述**：若累加器为零，则跳转到指定地址。  
   - **操作**：`if acc == 0 then pc <- <address>`  
   2. **Branch if Equal to Zero (Переход, если равно нулю)**  
      - **Синтаксис**: `beqz <address>`  
      - **Описание**: Перейти по адресу, если аккумулятор равен нулю.  
      - **Операция**: `if acc == 0 then pc <- <address>`  

3. **不等于零则分支**  
   - **语法**：`bnez <address>`  
   - **描述**：若累加器非零，则跳转到指定地址。  
   - **操作**：`if acc != 0 then pc <- <address>`  
   3. **Branch if Not Equal to Zero (Переход, если не равно нулю)**  
      - **Синтаксис**: `bnez <address>`  
      - **Описание**: Перейти по адресу, если аккумулятор не равен нулю.  
      - **Операция**: `if acc != 0 then pc <- <address>`  

4. **大于零则分支**  
   - **语法**：`bgt <address>`  
   - **描述**：若累加器大于零，则跳转到指定地址。  
   - **操作**：`if acc > 0 then pc <- <address>`  
   4. **Branch if Greater Than Zero (Переход, если больше нуля)**  
      - **Синтаксис**: `bgt <address>`  
      - **Описание**: Перейти по адресу, если аккумулятор больше нуля.  
      - **Операция**: `if acc > 0 then pc <- <address>`  

5. **小于零则分支**  
   - **语法**：`ble <address>`  
   - **描述**：若累加器小于零，则跳转到指定地址。  
   - **操作**：`if acc < 0 then pc <- <address>`  
   5. **Branch if Less Than Zero (Переход, если меньше нуля)**  
      - **Синтаксис**: `ble <address>`  
      - **Описание**: Перейти по адресу, если аккумулятор меньше нуля.  
      - **Операция**: `if acc < 0 then pc <- <address>`  

6. **溢出标志置位则分支**  
   - **语法**：`bvs <address>`  
   - **描述**：若溢出标志`V`置位，则跳转到指定地址。  
   - **操作**：`if overflow == 1 then pc <- <address>`  
   6. **Branch if Overflow Set (Переход, если флаг переполнения установлен)**  
      - **Синтаксис**: `bvs <address>`  
      - **Описание**: Перейти по адресу, если флаг переполнения `V` установлен.  
      - **Операция**: `if overflow == 1 then pc <- <address>`  

7. **溢出标志清除则分支**  
   - **语法**：`bvc <address>`  
   - **描述**：若溢出标志`V`清除，则跳转到指定地址。  
   - **操作**：`if overflow == 0 then pc <- <address>`  
   7. **Branch if Overflow Clear (Переход, если флаг переполнения очищен)**  
      - **Синтаксис**: `bvc <address>`  
      - **Описание**: Перейти по адресу, если флаг переполнения `V` очищен.  
      - **操作**：`if overflow == 0 then pc <- <address>`  

8. **进位标志置位则分支**  
   - **语法**：`bcs <address>`  
   - **描述**：若进位标志`C`置位，则跳转到指定地址。  
   - **操作**：`if carry == 1 then pc <- <address>`  
   8. **Branch if Carry Set (Переход, если флаг переноса установлен)**  
      - **Синтаксис**: `bcs <address>`  
      - **Описание**: Перейти по адресу, если флаг переноса `C` установлен.  
      - **操作**：`if carry == 1 then pc <- <address>`  

9. **进位标志清除则分支**  
   - **语法**：`bcc <address>`  
   - **描述**：若进位标志`C`清除，则跳转到指定地址。  
   - **操作**：`if carry == 0 then pc <- <address>`  
   9. **Branch if Carry Clear (Переход, если флаг переноса очищен)**  
      - **Синтаксис**: `bcc <address>`  
      - **Описание**: Перейти по адресу, если флаг переноса `C` очищен.  
      - **操作**：`if carry == 0 then pc <- <address>`  

10. **停机**  
    - **语法**：`halt`  
    - **描述**：停止机器运行。  
    10. **Halt (Останов)**  
        - **Синтаксис**: `halt`  
        - **Описание**: Остановить работу машины.  