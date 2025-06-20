# Основные концепции

### 1. ISO/IEC 12207:2010: Жизненный цикл ПО. Группы процессов ЖЦ.

生命周期（ЖЦ ПО）--- 是指软件从最初构思到最终停止使用的整个过程。

**ЖЦ ПО:**
- Разработка требований (заказчик, программисты) - 客户与开发人员共同定义需求
- Анализ - 分析师提出解决方案
- Проектирование архитектуры - 设计软件架构和实现模式
- Разработка - 开发者编写代码 
- Тестирование - 测试功能与性能
- Внедрение в эксплуатацию - 部署到生产环境
- Эксплуатация (багфиксы, поддержка пользователей, обновления) - 用户支持、缺陷修复、产品更新
- Вывод из эксплуатации (напр. Перенос данных на другую систему/ОС) /- 数据迁移（如更换OS）、停用旧系统

**Группы ЖЦ ПО:**
- Процесс согласования (2) - 合同与采购协议（如外包）
- Процесс организационного обеспечения (5) - 资源管理、培训、基础设施
- Процессы проекта (7) - 项目计划、风险管理、监控
- Технологические процессы (11) - 需求分析、设计、测试、部署	
- Процесс реализации программного средства (7) - 编程、集成、代码维护
- Процесс поддержки ПС (8) - 文档、配置管理、问题修复
- Процесс повторного использования ПС (3) - 复用组件管理

生命周期终点是“最后一个用户停止使用旧系统”
每个过程按 “输入 → 活动 → 输出” 标准化

---

### 2. Модели ЖЦ (последовательная, инкрементная, эволюционная).

**Модель ЖЦ ПО** --- структра, определяющая последовательность выполнения и взаимосвязи процессоров, действий и задач на протяжении всего ЖЦ.

>软件生命周期模型是一种定义整个生命周期中处理器、动作和任务的执行顺序和相互关系的结构。

#### 顺序模型 (Последовательная модель) 

Определены все требования, один этап разработки.（照片）

**核心思想**：将开发过程划分为线性、顺序的阶段，每个阶段必须完全完成后才能进入下一阶段，无迭代。

**代表**：瀑布模型

**优点**：容易计算时间期限（虽然可能和实际不符），开发成本。

**缺点**：过程中的变更可能会导致严重问题。

例如，如果需要对需求进行变更，这可能会导致需要重新开发已开发好的产品。

#### 增量模型 (Инкрементная модель)

Определены все требования, несколько этапов разработки.（打印机）

**核心思想**：将项目分解为多个 “增量”，逐个开发并交付，每个增量实现部分功能，逐步构建完整系统。重要的是，“增量” 既可以拆分为多个部分，也可以代表一个完整的产品。

**优点**：早期交付可用功能，客户可及时反馈。降低需求变更风险，适合需求渐进明确的项目。

**缺点**：架构易僵化，后期集成可能出现兼容性问题。文档更新频繁，管理复杂度高。

每个增量包含 “分析→设计→编码→测试→集成” 环节，按优先级逐步实现功能。

#### 演化模型 (Эволюционаая модель)

Определены не все требования, несколько этапов разработки.（画画）

**核心思想**：通过迭代开发，逐步演化系统，允许需求动态调整，强调反馈和风险控制。

**代表**：螺旋模型（Spiral Model）

**优点**：适应需求变化，支持动态调整。早期暴露风险，降低项目失败概率。

**缺点**：对风险分析能力要求高。频繁修改会导致架构混乱

一般用增量 - 演化式模型，因为纯粹的演化式开发在现实生活中很少存在（不过，例如，在产品开发过程中，项目完全有可能从最初很简单，逐渐发展变得复杂 ）。

Простейшим примером является методология SCRUM — это эволюционная модель с коротким циклом производства.

---

### 3. Водопадная (каскадная) модель.

**小型程序**：它包含两个阶段 —— 分析和编码。通常这类产品仅供开发它们的人员使用，用于内部用途。

**大型程序**：新增了需求分析、设计、测试阶段，以及按执行顺序进行的投入使用阶段。

>瀑布模型中标准的*阶段顺序*如下：
    - 确定对软件的需求。
    - 进行需求分析。
    - 设计程序。
    - 编写代码。
    - 进行测试。
    - 实施软件。
修改过程：测试阶段→编写代码→确认需求。

Стандартная последовательность шагов в каскадной модели такова:
- Определяются требования.
- Определяются требования к ПО.
- Требования анализируются.
- Проектируется программа.
- Разрабатывается код.
- Проводится тестирование.
- ПО вводится в эксплуатацию.

一旦进入到后续阶段，若要回头修改前期阶段的成果，成本往往很高，因为需要回溯多个已完成的步骤，会对整体进度和资源产生较大影响，所以它比较适合需求明确且稳定、技术成熟、项目规模相对适中且变更可控的软件开发场景。但在需求频繁变化的现代软件开发中，其灵活性不足的问题也较为突出。

---

### 4. Методология Ройса.

基于瀑布模型，罗伊斯通过五个额外步骤对其进行扩展，这些步骤能把有风险的开发过程转变为可交付所需产品的开发过程 。

1. **Предварительный дизайн**：罗伊斯在软件需求和分析之间界定了系统初步设计阶段。尽管在未开展实际分析时明确所有需求是有必要的，但程序设计师能够发现存在会影响实现的特性。对未来系统的模型（形象）进行设计、明确并构建，在开发工作前确定好数据逻辑基础。
   
2. **Документирование**：软件开发过程中重要的文档。
   - 系统需求
   - 初步设计规范
   - 详细设计规范
   - 系统设计最终规范
   - 测试计划
   - 使用说明
  
3. **Do it twice**：对程序执行轨迹进行模拟测试（与主程序并行），并在缩短开发时间的 “准测试环境” 中对其开展测试。这有助于验证或推翻软件的主要特性。
   
4. **Тестирование**：从成本和时间角度来看，测试是风险最高的阶段，也是最可能发现异常情况的最后环节。在规划测试时，罗伊斯提出，系统设计师可以借助程序开展 “视觉检查” —— 由他人重新审视代码，无需进行深入分析，只需标记出肉眼可见的缺陷，在程序模拟执行的每个步骤中进行防护（尽管这比较耗时 ） 。此外，修复大部分简单错误后，要在无保护的测试环境外壳中对程序进行检查（checkout）。
   
5. **Подключение пользователя**：三个需要用户参与体验、评估和确认的节点---初步检查、关键检查和最终检查。

---

### 5. Традиционная V-chart model J.Munson, B.Boehm.

![V-chart](../image/V-chart.png)

**V模型的基础是与瀑布模型相同的步骤序列，但每个开发层级都对应着自身的测试层级**。模块测试、集成测试和开发依次开展，依据程序版本标准、对应开发层级的任务要求进行。最后一个阶段是增量测试，在此阶段检查产品是否符合主要功能需求。

要开展测试，首先需要编制正确的软件需求规格说明（程序任务），因为测试的目的是确定程序行为是否与最终的正确行为相符。虽然**标准行为**往往难以界定，但它应该**在系统开发阶段被确定**。

动态测试（V 的右半部分）需要在计算机上执行测试，而静态测试则是在不执行开发成果（如规格说明、技术方案、设计等）的情况下对其进行检查。

静态测试可以在项目早期阶段进行，这有助于在测试过程中发现严重错误，避免开发出无功能或无法使用的产品。

---

### 6. Многопроходная модель (Incremental model).

考虑到一次性完成产品制作的难度，有人提议将**产品拆分为单独的功能和技术需求**，而生产过程（包括设计、实施以及技术集成）分多个轮次进行，每个轮次形成独立的版本包，这些版本包被称为功能增量，或者简称增量。

增量式方法能**大幅降低客户需求变更**的成本。开发过程变得更易管控，开发进度会形成文档且对客户可见，客户可以进行评论。

增量式方法也存在缺点。主要缺点在于，**系统架构有过时和退化的趋势**，随着时间推移，会开始需要重构（即整体或部分重新设计），相应地需要客户承担资金成本。程序版本包的文档很难维护。

另外一个**难点是签订开发合同**。传统的合同签订方法要求把总金额清晰拆分到各个开发阶段。但这个模型下很难考虑到潜在的变更情况，也难以将已投入工时的费用核算纳入其中 。

>Параллельная разработка частей продукта а в последствии интегрирование воедино.
并行开发产品的各个部分，然后将其集成为一个整体。
Снижение стоимости внесения изменений.
降低变更成本。
Возможность использования частично разработанной системы.
可以使用部分开发的系统。
Имеет тенденцию к устареванию, деградации. Требует рефакторинга с течением времени.
容易过时和退化。随着时间的推移，需要重构。
При параллельной разработке несколькими командами требует стабильного API, спланированного заранее.
由多个团队并行开发时，需要稳定的API，并提前规划。
Сложно рассчитать стоимость разработки.
开发成本难以计算。

---

### 7. Модель прототипирования (80-е). （旋涡模型）

**基于连续原型（последовательных прототипов）的开发方法**，可快速评估所开发软件的有用质量、减少架构错误的负面影响，每个原型都会细化架构和功能需求范围。开发的每个步骤都为后续扩展预留框架。这样，软件就以渐进演化的方式逐步构建。

首先规划整个迭代。之后快速分析当前需求及实现这些需求的方法。根据分析结果编制用户访谈问卷、开发功能，并与系统用户共同进行验证。

这会对用户对当前原型及其架构方案的满意度进行检验，对新软件开展测试。如果用户满意，且该原型可作为具备功能的产品投入使用，便进入软件后续开发阶段。

如果不满意，就再创建一个新原型，配备新数据库、界面等，和最初的原型类似，但会修正所有错误。向用户演示原型，展现程序在无实际产品情况下的运行逻辑。根据演示结果，用户可对产品所有规划特性进行测试。

---

### 8. RAD методология.

**快速应用开发(Rapid Application Development)**

在此过程中，用户直接参与开发流程，也就是说，程序员的功能需求和用户的需求产生了交集。借助自动化工具，用户能够创建项目和界面。

**阶段**：
1. 规划(Планирование) - 项目目标、范围、系统需求以及开发过程中可能遇到的困难。
2. 用户设计(Пользовательское проектирование) - 用户与系统分析师互动，开发包含所有必要系统功能的模型和原型。用户设计是一个漫长的互动过程，最终用户会选择符合其需求的工作模型。
3. 设计(Конструирование) - 程序和应用程序的开发。用户仍参与其中，并提出修改和改进建议。
4. 切换(Переключение) - 测试、过渡到新系统、用户培训。

---

### 9. Спиральная модель.

**大型软件产品的开发方法**，该方法被命名为螺旋模型。

螺旋的**每个 “圈” 都对应产品开发的一个阶段**，后一阶段会延续前一阶段已完成的工作。首先明确本阶段需要完成的主要任务，确定本阶段需考虑的替代方案和约束条。

接着**进行风险分析**，通过降低风险发生的概率，尽量减少软件开发所需的操作步骤。在螺旋模型的每个 “圈” 中，创建新版本产品前，都会评估风险等级。

风险分析完成后，**开展软件版本的开发与验证工作**。在螺旋的不同阶段，组件开发会基于整合前期阶段已管控的软件（包括软件产品代码）。在最后一次迭代结束时，会用 V 模型的部分流程对软件进行检验，即开展成品软件的测试。

在 “圈” 的最后一部分，会**对下一次迭代进行规划**。

这个模型将项目中出现的变更纳入开发流程的必要组成部分，并确定这些变更可根据其给开发流程带来的风险，决定采纳、否决或忽略。

---

### 10. UML Диаграммы: Структурные и поведенческие.

UML 语言是一种通用的图形建模语言。其主要目的是以图形方式表示软件开发的主要方面（规范、可视化、设计、文档）。

#### 结构化 UML

描述对象和应用程序的结构（类/对象图、组件图、развертывания|部署图、包图）。

**对象（object）**—— 是具有独特性的实体，其自身包含状态和行为。例如，对象 “我最喜欢的饼干” 可以表示为它的成分、放在我盘子里的位置，以及能在我手中融化的特性（这一点我可以通过吃饼干的行为来验证 ）。

**类（class）**—— 是对具有共同属性和操作的一组对象的描述。类的概念源于面向对象编程范式，从语义上与从现实世界中抽象出来的概念相关联，用于对这些概念进行建模，并确定它们的语法。例如，可能存在 “饼干” 类和抽象类 “面粉” 。

**接口（interface）**—— 是一个命名的对象集合，定义了对象应该具备的行为，但自身并不实现这些行为，而是为实现提供了必要的契约。例如，如果饼干凉了，我们可以使用微波炉，它实现了加热的接口。

**协作（collaboration**）—— 是为了实现某个既定目标或准备目标而相互作用的对象的集合。比如，住在顶层公寓的 “卡尔森”，为了准备食物，他需要一个平底锅，而卡尔森成功拿到了平底锅。

**参与者（actor）**—— 是外部的、未在系统中实现的事物，作为与系统交互的发起者。参与者可以表现为角色、另一个交互系统等形式。

**组件（component）**—— 是系统的模块化部分，具有明确界定的所需接口集合和所提供的接口集合。

**工件（artifact**）—— 是工作的成果，是开发活动的结果，比如之前提到 RUP 时说的最终产品。

**节点（node）**—— 是计算资源、系统或计算机，在其上部署和使用组件与工件。


#### 行为化 UML

展示系统内部交互的发生方式（деятельности|活动图、状态图、use-case|用例图、последовательности|序列图）。

**用例（use case）** --- 是一种实体，它定义了行动（一个或一组行为），系统对参与者（发起系统执行的角色 ）执行这些行动，以产生可观测的结果。在网站上，应用的是 “客户下单” 用例，该用例描述了客户下单并收到披萨的流程。

**状态** --- 对象整个生命周期中的一个阶段，其特征是对象有一组独特且语义不同的重要内部属性。吃饱或饥饿的状态会使卡尔森进入 “开心” 或 “不开心” 状态。状态也可以用连续的单调行为来表示，例如 “正往顶层公寓走”。

**活动** --- 本质上是对现实领域有意义的对象的一组行为。

**行为** --- 简单的计算 man.eat(pie)

#### 辅助类

**包（Package）** --- 这是一种逻辑分组实体。包除了用于分组外，没有其他语义内容。

为了提高图的可读性，还规定了**注释实体**。

---

### 11. UML: Use-case модель.

用例模型是一种以图形方式显示需求的工具，旨在简化利益相关者之间的交互。

include 构造型组织了用例的层次结构，并允许将一个通用活动包含在多个用例中。

extend 构造型（功能扩展点）表示对基本功能的扩展。

例如，在图书发行系统中，扩展点是收取逾期还书罚款，即在特定条件下激活特​​定功能。

#### 依赖关系（Отношение зависимости）

用于展示源元素依赖于目标元素，且命名的目标元素的变更可能会影响源元素。

例如，在需求模型中，客户端类可能依赖于订单类，因为客户端对象的行为可能在订单的使用场景中进行描述。
如果订单的名称或行为发生了变化（比如，添加了新的退货流程），那么客户端类的名称也必须改变，并且在项目类中，也需要添加这个属性。

**关联（Ассоциация）**用于描述一个元素与其他元素的连接。连接的语义内容取决于它是如何命名和解释的。存在不同类型的关联，用于描述补充语义：
- **聚合**：目标元素是源元素的一部分，源元素可以独立存在。例如，汽车由发动机、车身等组成，没有发动机，汽车依然可以作为一个整体概念存在（虽然无法行驶）。
- **组合**：是一种更严格的聚合形式，部分无法独立于整体存在，只能通过整体来创建和销毁。比如，汽车的车轮是汽车的一部分，没有汽车，单独的车轮在这个组合关系里就失去了作为汽车组件的意义。
- **包含**：源元素包含目标元素，并且可以访问其命名空间。这种关联通常用于包图中。

**泛化（Обобщение）**：源元素是目标元素的更一般化描述。更具体的目标元素可以扩展它，它可以在面向对象的概念中被继承。箭头指向父类（被继承的类）。

**实现（Реализация）**：源元素（比如，类）实现了由目标元素（比如，接口）定义的契约。

所有这些关系的细节可以通过 stereotypes（构造型 ）来细化。
在包图中，常用的构造型有 use（使用 ）、import（导入 ）、access（访问 ）、trace（跟踪 ）、merge（合并 ），它们可以明确包之间的关系类型。

---

### 12. UML: Диаграмма классов.

描述领域（也称为领域模型 ）的类图，表示软件系统静态结构模型的图表

举例：该模型的核心实体是动画制作订单，订单有必要的子订单，这些子订单通过泛化关系关联。每个儿童（Child）可以有多个这样的订单，每个订单会分配给执行者（Executor），执行者（Executor）可以同时处理多个订单。

类图可以反映：

- 主题领域中各个实体（例如对象和子系统）之间的各种关系
- 对象的内部结构（字段、方法）和关系类型（继承、接口实现）

随着需求的细化，设计模型可以得到改进。

---

### 13. UML: Диаграмма последовательностей

**Диаграмма последовательностей 序列图**

顺序图，它是 UML（统一建模语言）中的一种交互图，用于展示对象之间的消息传递顺序和时间先后关系，通过垂直生命线和水平消息线直观呈现系统动态行为，常用于分析和设计软件系统的交互流程。

**Диаграмма состояния 状态图**

状态图，根据 UML2 定义的有限状态机图，该图的详细程度与程序代码的实现程度相对应，展示身份验证状态以及注册用户查看页面的授权状态。

---

### 14. UML: Диаграмма размещения

Диаграмма размещения用于对系统的物理架构进行建模，包括硬件、网络基础设施以及软件构件在该基础设施节点上的分布。Диаграмма размещения展示了给定系统在部署时（即运行时）的硬件（或资源）和软件配置。

---

### 15. UP методологии (90-е). RUP: основы процесса.

该流程涵盖了整个软件开发过程。除了这些内容，在 RUP 中还存在所谓的 “角色” 。角色是一组职责，参与开发的人员承担这些职责以开展日常活动。RUP 总共包含约 30 个不同的角色。

每个参与开发的角色都有自己的一组活动。在进入角色的工作时，会生成工作成果，即工件。开发中的工件是角色工作的任意成果，比如设计文档、图形化说明、所使用的代码以及用户手册等。工件构成了流程各元素的基础，这些元素随后相互结合，形成完整的流程。

Процесс разбит на фазы. Также есть понятие Дисциплины – набор правил и указаний, которые необходимы для решения определенной задачи.

Фазы:
1. Начало
2. Проектирование
3. Построение
4. Внедрение

Дисциплины:
1. Бизнес-моделирование
2. Требования
3. Аналитика и проектирование
4. Реализация
5. Тестирование
6. Развертывание
7. Управление конфигурациями и изменениями
8. Управление проектом
9. Управление средой проекта

---

### 16. RUP: Фаза «Начало».

在 “起始” 阶段的主要工作方向是评估项目：
- 明确需要投入多少资源和时间
- 确定用户会遇到哪些问题
- 以及借助怎样的产品适用性，软件可解决这些问题

会形成名为 “构想”的工件(**artefact**)

**Цели**

- Определить границы (область применения) проекта
- Описать основные сценарии использования системы
- Предложить возможное технологическое решение (API, сторонние решения, технологии)
- Рассчитать стоимость и разработать график работ
- Оценить риски, подготовить окружение

**目标**

- 定义项目范围
- 描述系统的主要使用场景
- 提出可能的技术解决方案（API、第三方解决方案、技术）
- 计算成本并制定工作计划
- 评估风险，准备环境

**里程碑**

各方是否就时间、成本、要求、优先级和技术达成一致？
是否已评估风险并选择了缓解策略？

---

### 17. RUP: Фаза «Проектирование».

在 “设计” 阶段主要任务是开发并测试稳定且灵活的系统架构，创建并测试若干原型系统，这些原型可对架构进行说明。
该阶段的主要成果是依据需求确定的架构，以及实施新架构的时间和成本评估。

**Цели**

- Финализировать базовую архитектуру системы
- Разработать прототип(ы) на основе архитектуры
- Убедиться в том, что архитектура, планы и сроки стабильны, риски разработаны и учтены
- Продемонстрировать, что в архитектуре можно будет реализовать требования с разумными сроками и стоимостью

**目标**

- 确定基准系统架构
- 基于架构开发原型
- 确保架构、计划和时间表稳定，并已开发和处理风险
- 证明架构能够在合理的时间和成本内实现需求

**里程碑**

项目概念、需求和架构是否稳定？
原型测试标准是否明确？
原型是否经过测试并证明不存在重大风险？
开发计划是否详细且经济实惠？
计划/实际成本比率是否可接受，各方是否同意项目可行？

---

### 18. RUP: Фаза «Построение».

在 构建” 阶段会依照项目计划创建产品所需的必要版本（发布包），直至交付给客户。

**Цели**

- Экономически эффективно, с надлежащим качеством, так быстро, как возможно, разработать продукт
- Провести анализ, проектирование, разработку и тестирование
- Подготовить продукт, места установки и пользователей к использованию
- Изменений и улучшений в архитектуру вноситься не должно или они должны быть минимальны

**目标**

- 尽快以经济高效的方式开发出质量合格的产品
- 进行分析、设计、开发和测试
- 做好产品、安装场地和用户的准备
- 尽量减少或不进行架构变更或改进

**里程碑**
产品是否稳定？
各方是否已准备好交付产品？
实际成本与计划成本相比是否可接受？

---

### 19. RUP: Фаза «Внедрение».

在实施阶段，企业家要做出将产品投入工业使用的决策，并开始从中获取收益。关键是要在未来项目的环境中对其进行正确测试。需要评估它们与在起始阶段制定的规范的符合程度。尤其要把控好，因修复错误所需的工作，不会导致开发成本大幅增加。

**Цели**

- Провести бета-тестирование, сравнить работоспособность старой и новых версий
- Запустить маркетинг и продажи
- Отладить процессы устранения сбоев, дефектов, проблем с производительностью
- Убедиться в самодостаточности пользователей
- Провести (совместно со всеми заинтересованными сторонами) открытый анализ соответствия разработанного продукта исходной концепции

**目标**

- 进行 Beta 测试，比较新旧版本的功能
- 启动市场营销和销售
- 调试流程，以解决故障、缺陷和性能问题
- 确保用户能够独立使用
- 与所有利益相关者一起，对开发产品与原始概念的一致性进行公开分析

**里程碑**
用户是否满意？
最终的计划成本与实际成本的比例是否可接受？

---

### 20. Манифест Agile (2001).

随着技术和社会的发展，业务需求和产品需求也在不断变化，因此需要一种能够快速灵活地应对这些变化的方法。敏捷方法应运而生。

敏捷方法将客户需求及其响应放在首位。当然，如果项目预算固定，则无法实现这一点，因为没有扩展空间。

我们不断探索更好的软件开发方法，既包括直接开发，也包括帮助他人开发。通过这些工作，我们逐渐认识到：

- 人员和互动比流程和工具更重要；
- 一个可用的产品比完整的文档更重要；
- 客户协作比商定合同条款更重要；
- 做好应对变化的准备比遵循原计划更重要。

因此，在不否认右侧内容重要性的情况下，我们仍然更重视左侧内容。

---

### 21. Scrum.

在Scrum中，开发流程本身被简化。Scrum 的主要且唯一的服务构件是待办事项列表 (backlog) --- 一份按优先级排序的需求列表，其中包含对开发工作量的评估。

- 产品待办事项列表更为通用，包含业务需求
- 冲刺待办事项列表更为详细，考虑到了实施的技术特性
- 冲刺周期为 2-4 周，在此期间，开发人员会从冲刺待办事项列表中选定一组需求进行实施
- 每个冲刺都以一个演示版本结束，并向客户演示已完成的工作。在几个冲刺之后会举行回顾会议（用于纠正错误和重新分配角色
- Scrum 中的团队由 3-10 人组成

其中有两个特殊角色：

- Владелец продуктов (产品负责人)，负责确定开发待办事项列表中需求的顺序（如果是业务客户，他还会创建这些需求）；
- Scrum Master，负责组织每日 Scrum 会议，帮助团队规划冲刺并监控团队内部关系。

Scrum 的优点是简单、行政工作和文书工作最少、最大程度地集中于工作代码。

---

### 22. Disciplined Agile 2.X (2013).

事实上，显而易见的是，这种灵活的方法论的主要弱点在于可扩展性。对积极进取的创业者来说是有效的办法，但是难以扩展到拥有大量开发人员的团队。

Disciplined Agile 2.X 方法基于DAD（Disciplined Agile Delivery，规范敏捷交付）方法，DAD 方法本身基于 Scrum，但与 RUP 相比更偏向轻量级。

DAD方法将开发阶段划分为初始（启动）、构建、转型和生产，这与 RUP非常相似，详细描述了每个开发阶段的流程，但主要的开发周期建立在灵活的方法（包括Scrum）的基础上。

DAD还考虑了超越开发流程本身的流程。其中包括：
- 架构和代码重用管理
- 人员管理
- 开发公司的支持服务和当前运营
- 能力组合管理
- 开发流程和支持流程的持续改进等。