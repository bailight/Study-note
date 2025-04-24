# Acc32 指令集架构（ISA）文档

Acc32 ISA 是一种基于累加器的简单指令集，专为教育目的而设计。本文档概述了 Acc32 ISA 中可用的指令、其语法和语义。

Acc32 汇编代码中的注释以 `;` 字符表示。

## ISA 特定状态视图

- `Acc:dec`，`Acc:hex` -- `Acc` 寄存器。
- `V` -- 溢出标志。
- `C` -- 进位标志。

## 指令

指令大小：操作码 1 字节，绝对操作数 4 字节，相对操作数 2 字节。控制流、立即/间接/地址加载/存储使用绝对地址，其他使用相对地址。

### 数据移动指令

- **立即加载**
    - **语法：** `load_imm <地址>`
    - **描述：** 将立即值加载到累加器中。
    - **操作：** `acc <- <地址>`

- **加载**
    - **语法：** `load <偏移量>`
    - **描述：** 将相对地址中的值加载到累加器中。
    - **操作：** `acc <- mem[pc + <偏移量>]`

- **存储**
    - **语法：** `store <偏移量>`
    - **描述：** 将累加器的值存储到相对地址中。
    - **操作：** `mem[pc + <偏移量>] <- acc`

- **加载地址**
    - **语法：** `load_addr <地址>`
    - **描述：** 将特定地址中的值加载到累加器中。
    - **操作：** `acc <- mem[<地址>]`

- **存储地址**
    - **语法：** `store_addr <地址>`
    - **描述：** 将累加器的值存储到特定地址中。
    - **操作：** `mem[<地址>] <- acc`

- **间接加载**
    - **语法：** `load_ind <地址>`
    - **描述：** 将间接地址中的值加载到累加器中。
    - **操作：** `acc <- mem[mem[<地址>]]`

- **间接存储**
    - **语法：** `store_ind <地址>`
    - **描述：** 将累加器的值存储到间接地址中。
    - **操作：** `mem[mem[<地址>]] <- acc`

### 算术指令

- **加法**
    - **语法：** `add <地址>`
    - **描述：** 将特定地址中的值加到累加器中。
    - **操作：** `acc <- acc + mem[<地址>]` 并设置 `C` 和 `V` 标志。

- **减法**
    - **语法：** `sub <地址>`
    - **描述：** 从累加器中减去特定地址中的值。
    - **操作：** `acc <- acc - mem[<地址>]` 并设置 `V` 标志。

- **乘法**
    - **语法：** `mul <地址>`
    - **描述：** 将累加器乘以特定地址中的值。
    - **操作：** `acc <- acc * mem[<地址>]` 并设置 `V` 标志。

- **除法**
    - **语法：** `div <地址>`
    - **描述：** 将累加器除以特定地址中的值。
    - **操作：** `acc <- acc / mem[<地址>]`

- **取余**
    - **语法：** `rem <地址>`
    - **描述：** 计算累加器除以特定地址中的值的余数。
    - **操作：** `acc <- acc % mem[<地址>]`

- **清除溢出标志**
    - **语法：** `clv`
    - **描述：** 清除溢出标志。
    - **操作：** `overflow <- 0`

### 位操作指令

- **左移**
    - **语法：** `shiftl <地址>`
    - **描述：** 将累加器左移特定地址中的位数（不使用进位标志）。
    - **操作：** `acc <- acc << mem[<地址>]`

- **右移**
    - **语法：** `shiftr <地址>`
    - **描述：** 将累加器右移特定地址中的位数（不使用进位标志）。
    - **操作：** `acc <- acc >> mem[<地址>]`

- **按位与**
    - **语法：** `and <地址>`
    - **描述：** 将累加器与特定地址中的值进行按位与操作。
    - **操作：** `acc <- acc & mem[<地址>]`

- **按位或**
    - **语法：** `or <地址>`
    - **描述：** 将累加器与特定地址中的值进行按位或操作。
    - **操作：** `acc <- acc | mem[<地址>]`

- **按位异或**
    - **语法：** `xor <地址>`
    - **描述：** 将累加器与特定地址中的值进行按位异或操作。
    - **操作：** `acc <- acc ^ mem[<地址>]`

- **按位取反**
    - **语法：** `not`
    - **描述：** 对累加器进行按位取反操作。
    - **操作：** `acc <- ~acc`

### 控制流指令

- **跳转**
    - **语法：** `jmp <地址>`
    - **描述：** 跳转到特定地址。
    - **操作：** `pc <- <地址>`

- **等于零则分支**
    - **语法：** `beqz <地址>`
    - **描述：** 如果累加器为零，则跳转到特定地址。
    - **操作：** `if acc == 0 then pc <- <地址>`

- **不等于零则分支**
    - **语法：** `bnez <地址>`
    - **描述：** 如果累加器不为零，则跳转到特定地址。
    - **操作：** `if acc != 0 then pc <- <地址>`

- **大于零则分支**
    - **语法：** `bgt <地址>`
    - **描述：** 如果累加器大于零，则跳转到特定地址。
    - **操作：** `if acc > 0 then pc <- <地址>`

- **小于零则分支**
    - **语法：** `ble <地址>`
    - **描述：** 如果累加器小于零，则跳转到特定地址。
    - **操作：** `if acc < 0 then pc <- <地址>`

- **溢出标志置位则分支**
    - **语法：** `bvs <地址>`
    - **描述：** 如果溢出标志置位，则跳转到特定地址。
    - **操作：** `if overflow == 1 then pc <- <地址>`

- **溢出标志清除则分支**
    - **语法：** `bvc <地址>`
    - **描述：** 如果溢出标志清除，则跳转到特定地址。
    - **操作：** `if overflow == 0 then pc <- <地址>`

- **进位标志置位则分支**
    - **语法：** `bcs <地址>`
    - **描述：** 如果进位标志置位，则跳转到特定地址。
    - **操作：** `if carry == 1 then pc <- <地址>`

- **进位标志清除则分支**
    - **语法：** `bcc <地址>`
    - **描述：** 如果进位标志清除，则跳转到特定地址。
    - **操作：** `if carry == 0 then pc <- <地址>`

- **停机**
    - **语法：** `halt`
    - **描述：** 停止机器运行。
  

---

# Acc32 Instruction Set Architecture (ISA) Documentation

The Acc32 ISA is a simple accumulator-based instruction set designed for educational purposes. This documentation provides an overview of the instructions available in the Acc32 ISA, their syntax, and their semantics.

Comments in Acc32 assembly code are denoted by the `;` character.

## ISA Specific State Views

- `Acc:dec`, `Acc:hex` -- `Acc` register.
- `V` -- Overflow flag.
- `C` -- Carry flag.

## Instructions

Instruction size: 1 byte for opcode, 4 bytes for absolute operand, 2 bytes for relative operand. Control flow, Load/Store Immediate/Indirect/Addr use absolute address, other -- relative.

### Data Movement Instructions

- **Load Immediate**
    - **Syntax:** `load_imm <address>`
    - **Description:** Load an immediate value into the accumulator.
    - **Operation:** `acc <- <address>`

- **Load**
    - **Syntax:** `load <offset>`
    - **Description:** Load a value from a relative address into the accumulator.
    - **Operation:** `acc <- mem[pc + <offset>]`

- **Store**
    - **Syntax:** `store <offset>`
    - **Description:** Store the accumulator value into a relative address.
    - **Operation:** `mem[pc + <offset>] <- acc`

- **Load Address**
    - **Syntax:** `load_addr <address>`
    - **Description:** Load a value from a specific address into the accumulator.
    - **Operation:** `acc <- mem[<address>]`

- **Store Address**
    - **Syntax:** `store_addr <address>`
    - **Description:** Store the accumulator value into a specific address.
    - **Operation:** `mem[<address>] <- acc`

- **Load Indirect**
    - **Syntax:** `load_ind <address>`
    - **Description:** Load a value from an indirect address into the accumulator.
    - **Operation:** `acc <- mem[mem[<address>]]`

- **Store Indirect**
    - **Syntax:** `store_ind <address>`
    - **Description:** Store the accumulator value into an indirect address.
    - **Operation:** `mem[mem[<address>]] <- acc`

### Arithmetic Instructions

- **Add**
    - **Syntax:** `add <address>`
    - **Description:** Add a value from a specific address to the accumulator.
    - **Operation:** `acc <- acc + mem[<address>]` and set `C` and `V` flags.

- **Subtract**
    - **Syntax:** `sub <address>`
    - **Description:** Subtract a value from a specific address from the accumulator.
    - **Operation:** `acc <- acc - mem[<address>]` and set `V` flags.

- **Multiply**
    - **Syntax:** `mul <address>`
    - **Description:** Multiply the accumulator by a value from a specific address.
    - **Operation:** `acc <- acc * mem[<address>]` and set `V` flags.

- **Divide**
    - **Syntax:** `div <address>`
    - **Description:** Divide the accumulator by a value from a specific address.
    - **Operation:** `acc <- acc / mem[<address>]`

- **Remainder**
    - **Syntax:** `rem <address>`
    - **Description:** Compute the remainder of the accumulator divided by a value from a specific address.
    - **Operation:** `acc <- acc % mem[<address>]`

- **Clear Overflow**
    - **Syntax:** `clv`
    - **Description:** Clear the overflow flag.
    - **Operation:** `overflow <- 0`

### Bitwise Instructions

- **Shift Left**
    - **Syntax:** `shiftl <address>`
    - **Description:** Shift the accumulator left by a number of bits from a specific address (Carry flag will not be used).
    - **Operation:** `acc <- acc << mem[<address>]`

- **Shift Right**
    - **Syntax:** `shiftr <address>`
    - **Description:** Shift the accumulator right by a number of bits from a specific address (Carry flag will not be used).
    - **Operation:** `acc <- acc >> mem[<address>]`

- **Bitwise AND**
    - **Syntax:** `and <address>`
    - **Description:** Perform a bitwise AND on the accumulator with a value from a specific address.
    - **Operation:** `acc <- acc & mem[<address>]`

- **Bitwise OR**
    - **Syntax:** `or <address>`
    - **Description:** Perform a bitwise OR on the accumulator with a value from a specific address.
    - **Operation:** `acc <- acc | mem[<address>]`

- **Bitwise XOR**
    - **Syntax:** `xor <address>`
    - **Description:** Perform a bitwise XOR on the accumulator with a value from a specific address.
    - **Operation:** `acc <- acc ^ mem[<address>]`

- **Bitwise NOT**
    - **Syntax:** `not`
    - **Description:** Perform a bitwise NOT on the accumulator.
    - **Operation:** `acc <- ~acc`

### Control Flow Instructions

- **Jump**
    - **Syntax:** `jmp <address>`
    - **Description:** Jump to a specific address.
    - **Operation:** `pc <- <address>`

- **Branch if Equal to Zero**
    - **Syntax:** `beqz <address>`
    - **Description:** Jump to a specific address if the accumulator is zero.
    - **Operation:** `if acc == 0 then pc <- <address>`

- **Branch if Not Equal to Zero**
    - **Syntax:** `bnez <address>`
    - **Description:** Jump to a specific address if the accumulator is not zero.
    - **Operation:** `if acc != 0 then pc <- <address>`

- **Branch if Greater Than Zero**
    - **Syntax:** `bgt <address>`
    - **Description:** Jump to a specific address if the accumulator is greater than zero.
    - **Operation:** `if acc > 0 then pc <- <address>`

- **Branch if Less Than Zero**
    - **Syntax:** `ble <address>`
    - **Description:** Jump to a specific address if the accumulator is less than zero.
    - **Operation:** `if acc < 0 then pc <- <address>`

- **Branch if Overflow Set**
    - **Syntax:** `bvs <address>`
    - **Description:** Jump to a specific address if the overflow flag is set.
    - **Operation:** `if overflow == 1 then pc <- <address>`

- **Branch if Overflow Clear**
    - **Syntax:** `bvc <address>`
    - **Description:** Jump to a specific address if the overflow flag is clear.
    - **Operation:** `if overflow == 0 then pc <- <address>`

- **Branch if Carry Set**
    - **Syntax:** `bcs <address>`
    - **Description:** Jump to a specific address if the carry flag is set.
    - **Operation:** `if carry == 1 then pc <- <address>`

- **Branch if Carry Clear**
    - **Syntax:** `bcc <address>`
    - **Description:** Jump to a specific address if the carry flag is clear.
    - **Operation:** `if carry == 0 then pc <- <address>`

- **Halt**
    - **Syntax:** `halt`
    - **Description:** Halt the machine.