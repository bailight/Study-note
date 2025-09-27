# Lab 2

---

### 1. Java-сервлеты. Особенности реализации, ключевые методы, преимущества и недостатки относительно CGI и FastCGI.

Java servlet。 CGI和FastCGI的实现特点、关键方法、优缺点。

Servlet 是一个 Java 类，用于处理客户端请求并返回响应。它在服务器端的 Servlet 容器（如 Tomcat）中运行。

#### 实现特点

Java servlet 是通过 JSP（JavaServer Pages）技术来实现动态网页的。JSP 是一种基于 Java 的页面编写语言，它允许在 HTML 中嵌入 Java 代码，从而实现动态页面的生成。Java servlet 和 JSP 组合起来，可以实现丰富的 Web 应用程序功能。与 CGI/FastCGI 不同，不会为每个请求创建新进程。容器使用多线程处理，为每个请求创建一个新线程，但使用同一个 Servlet 实例。这效率高得多。

#### 关键方法

- init(ServletConfig config): 在 Servlet 加载到内存时调用一次。用于初始化资源。
- service(ServletRequest request, ServletResponse response): 针对每个请求调用。确定方法（GET、POST）并将处理委托给相应的方法（doGet, doPost）。
- destroy(): 在从内存中卸载 Servlet 之前调用。用于释放资源。

**HttpServlet 类**

开发人员重写这些方法来处理特定的 HTTP 方法。

- doGet(HttpServletRequest request, HttpServletResponse response)：用于处理 GET 请求。
- doPost(HttpServletRequest request, HttpServletResponse response)：用于处理 POST 请求。
- doPut(HttpServletRequest request, HttpServletResponse response)：用于处理 PUT 请求。
- doDelete(HttpServletRequest request, HttpServletResponse response)：用于处理 DELETE 请求。
- doFilter(ServletRequest request, ServletResponse response, FilterChain chain)：用于过滤请求，实现中间件功能。

#### 与CGI和FastCGI相比的优缺点

**优点**

- 稳定性高：Java servlet 是通过 Java 虚拟机实现的，利用 Java 的内存管理和异常处理机制，因此具有更好的稳定性和可靠性。
- 高性能: 没有为每个请求创建进程的开销。
- 可移植性: 用 Java 编写，因此与平台无关。
- 与 Java 生态系统（JDBC、JNDI、EJB）集成更紧密。标准化的 API，所有容器都通用。
- Servlet 和 FastCGI 都使用长生命周期进程来处理多个请求。

**缺点**

- 开发难度较大：相比 CGI 和 FastCGI，Java servlet 的开发难度较大，需要熟悉 Java 语言和 JSP 技术。
- 学习曲线陡峭：Java servlet 的学习曲线比较陡峭，需要花费一定的时间和精力进行学习。
- 绑定在 Java 平台上。FastCGI 允许使用任何理解 FastCGI 协议的程序（如 Python、PHP）。

---

### 2. Контейнеры сервлетов. Жизненный цикл сервлета.

Servlet 容器。 Servlet 生命周期。

Servlet 容器（例如 Apache Tomcat, Jetty）: 这是一个为 Servlet 提供运行环境的程序。它管理它们的生命周期，处理网络连接（将 HTTP 请求转换为 ServletRequest 对象，并将响应转换回 HTTP），管理会话和安全性。

#### 提供服务

- **加载 Servlet：**容器加载和实例化 Servlet 类。
- **管理 Servlet 生命周期：**容器负责维护 Servlet 的生命周期状态，包括初始化、服务、销毁等。
- **处理请求和响应：**容器负责接收客户端请求，将它们路由到相应的 Servlet，并处理 Servlet 的响应。
- **提供公共服务：**容器还提供公共服务，例如日志记录、安全和事务处理。

流行的 Servlet 容器包括：

- Apache Tomcat
- WildFly

#### Servlet 生命周期

Servlet 生命周期描述 Servlet 从加载到销毁的各阶段。它由以下几个阶段组成：

1. **初始化：**容器调用 `init` 方法来初始化 Servlet。在此阶段，Servlet 初始化其配置和状态。
2. **服务：**当客户端请求到达时，容器调用 `service` 方法。`service` 方法负责处理请求和生成响应。
3. **销毁：**当 Servlet 不再需要时，容器调用 `destroy` 方法来销毁 Servlet。在此阶段，Servlet 释放其资源并关闭。

除了这些基本阶段，Servlet 容器还支持以下附加阶段：

- **加载：**在初始化 Servlet 之前，容器调用 `load` 方法。该方法用于对 Servlet 进行自定义设置或检查。
- **卸载：**在销毁 Servlet 之后，容器调用 `unload` 方法。该方法用于执行最后的清理或释放资源。

---

### 3. Диспетчеризация запросов в сервлетах. Фильтры сервлетов.

在 servlet 中分派请求。 Servlet 过滤器。

Servlet 可以使用多种机制将请求分派到其他 Servlet 或资源：

- **请求转发（Request Forwarding）：**服务器内部将请求转发到另一个 Servlet 或 JSP 页面，而不改变浏览器中的 URL。
- **重定向（Redirection）：**服务器向浏览器发出一个新的 HTTP 请求，将其重定向到另一个 URL。浏览器会收到一个新的 HTTP 响应。
- **包含（Including）：**将另一个 Servlet 或 JSP 页面的内容动态包含到当前响应中，就像它本身就是页面的一部分一样。

#### Servlet 过滤器

Servlet 过滤器是一种特殊的 Servlet，用于拦截请求和响应，以便在进入或离开 Servlet 时对其进行处理。过滤器主要用于以下目的：

- **身份验证和授权：**检查用户是否被授权访问资源。
- **数据验证：**验证请求中的输入是否有效。
- **内容压缩：**压缩响应以减少带宽使用。
- **安全：**防止跨站脚本攻击（XSS）和跨站请求伪造（CSRF）。

#### 使用过滤器分派请求

过滤器可以通过使用 `FilterChain` 接口来分派请求：

```Java
@Override
public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
    // 进行预处理...

    // 根据过滤器逻辑，决定是否分派请求
    if (shouldForward) {
        // 请求转发到另一个 Servlet 或 JSP 页面
        request.getRequestDispatcher("/targetServlet").forward(request, response);
    } else {
        // 继续在过滤器链中处理请求
        chain.doFilter(request, response);
    }
}
```

在上面的示例中，`shouldForward` 标志确定是否应将请求转发到其他资源。如果为 `true`，则使用 `forward()` 方法将请求转发；如果为 `false`，则过滤器将继续在过滤器链中处理请求。

---

### 4. HTTP-сессии - назначение, взаимодействие сервлетов с сессией, способы передачи идентификатора сессии.

HTTP 会话 - 目的、servlet 与会话的交互、传输会话标识符的方法

**HTTP 会话**

HTTP 是无状态协议，这意味着每次请求都被视为独立事件，与以前的请求没有关联。为了维护用户会话，HTTP 会话被引入。

**目的**

HTTP 会话用于：

- 跨多个请求跟踪用户状态
- 存储特定于会话的信息（例如购物车内容）

**Servlet 与会话的交互**

Servlet 广泛用于响应来自客户端的 HTTP 请求。可以使用 `request.getSession()` 方法访问与请求关联的会话对象。`HttpSession` 接口提供了用于存储和检索会话属性的方法。

**传输会话标识符的方法**

Web 服务器使用会话标识符来识别特定的会话。有两种主要方法可以传输会话标识符：

- **Cookie：** 服务器设置一个 Cookie，其中包含唯一的标识符，该标识符与会话相关联。浏览器会自动在后续请求中包含此 Cookie。
- **URL 重写：** 服务器将会话标识符附加到 URL 的查询字符串或片段中。浏览器在后续请求中发送相同的 URL。

**选择方法**

选择会话标识符的传输方法取决于应用程序的需求：

- **Cookie：** 更安全、更普遍，但不适用于禁用 Cookie 的浏览器。
- **URL 重写：** 适用于禁用 Cookie 的场景，但可能会产生较长的 URL 并存在安全隐患。

---

### 5. Контекст сервлета - назначение, способы взаимодействия сервлетов с контекстом.

**Servlet 上下文**

Servlet 上下文是一个数据结构，其中包含有关 Servlet 运行环境的信息。它提供了一系列方法，允许 Servlet 访问有关其容器，Web 应用程序和其他 servlet 的信息。

**Servlet 与上下文的交互**

Servlet 可以通过以下方式与上下文交互：

- **获取上下文对象：**Servlet 可以使用 `getServletContext()` 方法获取其上下文的引用。
- **访问属性：**Servlet 可以使用 `getAttribute(String name)` 方法获取与上下文关联的特定属性的值。
- **设置属性：**Servlet 可以使用 `setAttribute(String name, Object value)` 方法设置与上下文关联的属性。
- **日志记录：**Servlet 可以使用 `log()` 方法记录信息到上下文的日志文件中。
- **初始化参数：**Servlet 可以使用 `getInitParameter(String name)` 方法获取与 Web 应用程序关联的初始化参数的值。
- **资源加载：**Servlet 可以使用 `getResource(String path)` 和 `getResourceAsStream(String path)` 方法加载 Web 应用程序中的资源（例如 JSP 文件或图像）。

**Servlet 与上下文交互的目的**

Servlet 与上下文交互是为了：

- **访问环境信息：**获取有关容器、Web 应用程序和其他 Servlet 的信息。
- **共享信息：**将数据存储在 上下文中，使其可供其他 Servlet 和组件使用。
- **配置 Servlet：**使用初始化参数配置 Servlet 的行为。
- **日志记录：**记录信息和事件，以进行调试和故障排除。
- **加载资源：**获取访问 Web 应用程序中的文件和其他资源。

**示例代码**

以下代码示例演示了 Servlet 如何与上下文交互：

```Java
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/example")
public class ExampleServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        ServletContext context = getServletContext();

        // 获取属性值
        String contextParam = context.getInitParameter("context-param");

        // 设置属性值
        context.setAttribute("attribute-name", "attribute-value");

        // 日志记录
        context.log("Message to the log file");

        // 资源加载
        URL resourceURL = context.getResource("/myresource.jsp");

    }
}
```

---

### 6. JavaServer Pages. Особенности, преимущества и недостатки по сравнению с сервлетами, область применения.

Java 服务器页面。与 servlet 相比的特点、优点和缺点、范围。

**Java 服务器页面 (JSP)** 是一种基于 Java 的 Web 技术，它允许开发人员创建动态 Web 页面。与 servlet 类似，它是一种基于服务器的组件，用于处理用户请求并生成响应。

#### JSP 与 Servlet 的比较

**特点：**

- **基于标记：** JSP 使用 HTML 标记和特殊的 JSP 标记来创建页面。
- **动态页面：** JSP 页面能够访问服务器端代码和数据，从而允许开发动态 Web 页面。
- **简化开发：** JSP 使用标记化语法，这使得编写动态 Web 页面比使用 servlet 更容易。

**优点：**

- **易于使用：** 基于标记的语法使得 JSP 易于学习和使用，即使对于初学者也是如此。
- **简化代码：** JSP 标记减少了编写动态 Web 页面所需的代码量。
- **集成 Java：** JSP 完全集成到 Java 平台中，从而可以轻松访问 Java 库和框架。

**缺点：**

- **性能：** JSP 页面可能比 servlet 慢，因为它们需要被编译为 servlet 才能执行。
- **调试困难：** JSP 错误消息可能难以理解和调试。
- **安全性：** JSP 可能容易受到跨站点脚本 (XSS) 攻击，因为它们允许在客户端执行代码。

#### 范围

**请求范围：** 在一个请求的生命周期内可用。

**会话范围：** 在单个用户会话的生命周期内可用。

**应用范围：** 在 Web 应用程序的生命周期内可用。

**页面范围：** 仅在当前 JSP 页面中可用。


#### 优缺点

**优点**

- 方便
- 代码简化
- 与 Java 集成

**缺点**

- 性能问题
- 调试困难
- 安全漏洞

---

### 7. Жизненный цикл JSP.

JSP生命周期

JSP 生命周期包含一系列阶段，从 JSP 页面被请求到响应被生成和发送到客户端。这些阶段如下：

#### 1. 翻译

- JSP 页面被编译成 Servlet。
- Servlet 被加载到容器中。
- Servlet 的 `init()` 方法被调用，用于初始化 Servlet。

#### 2. 请求处理

- 当客户端向包含 JSP 页面的 URL 发送请求时，Servlet 的 `service()` 方法会被调用。
- `service()` 方法创建一个 `ServletRequest` 对象和一个 `ServletResponse` 对象，它们分别代表请求和响应。
- Servlet 的 `doGet()` 或 `doPost()` 方法（取决于请求类型）被调用，用于处理请求。

#### 3. JSP 页面评估

- 容器调用 JSP 页面中的所有表达式和脚本。
- 这些表达式和脚本生成动态内容，并将其写入响应中。

#### 4. 响应生成

- Servlet 的 `getWriter()` 或 `getOutputStream()` 方法被用于向响应中写入内容。
- 响应被发送到客户端。

#### 5. Servlet 销毁

- 当服务器不再需要 Servlet 时，Servlet 的 `destroy()` 方法会被调用。
- 容器从内存中卸载 Servlet。

**注意：**

- 翻译阶段只在第一次请求 JSP 页面时发生。 последующие запросы используют скомпилированный сервлет. （后续请求使用已编译的 servlet）
- 请求处理和 JSP 页面评估阶段在每次请求 JSP 页面时都会发生。

---

### 8. Структура JSP-страницы. Комментарии, директивы, объявления, скриптлеты и выражения.

JSP页面结构。注释、指令、声明、脚本和表达式。

JSP（JavaServer Pages）是用于构建动态网页的一种技术，它允许在 HTML 页面中插入 Java 代码。一个 JSP 页面通常包含以下主要结构组件：

#### 1. 注释

JSP 允许使用两种类型的注释：

- HTML 注释: 用于在 HTML 中添加注释，这些注释在浏览器中不可见。

    `<!-- 这是一个 HTML 注释 -->`

- JSP 注释: 这种注释在 JSP 代码中使用，并且不会被输出到客户端。

    `<%-- 这是一个 JSP 注释 --%>`

#### 2. 指令

指令用于定义 JSP 页面的全局属性，通常位于文件的顶部。指令以 <%@ %> 开头，常见的指令有：

- page 指令: 用于设置页面属性，例如内容类型、编码等。

   ` <%@ page contentType="text/html; charset=UTF-8" language="java" %>`

- include 指令: 用于包含其他 JSP 文件或资源。

    `<%@ include file="header.jsp" %>`

#### 3. 声明

声明用于定义类级别的变量和方法，位于 <%! %> 中。通过声明，开发者可以在 JSP 页面中定义 Java 代码。

```jsp
<%! 

  int count = 0; // 声明一个整数变量

  public int increment() { // 声明一个方法

    count++;

    return count;

  }

%>
```

#### 4. 脚本

脚本是能够在 JSP 页中嵌入 Java 代码的部分，使用 <% %> 语法。脚本可以包含任何有效的 Java 代码。

```jsp
<% 

  String message = "Hello, World!"; 

  out.println(message); // 输出内容到响应

%>
```

#### 5. 表达式

表达式用于输出内容，可以在 HTML 中直接插入。表达式使用 <%= %> 语法，JSP 会自动调用 out.println() 将表达式的值写入响应。

`<%= "当前时间: " + new java.util.Date() %>`

#### JSP 页面结构示例

一个简单的 JSP 页面可能看起来像这样：

```jsp
<%@ page contentType="text/html; charset=UTF-8" language="java" %>
<%@ include file="header.jsp" %>
<%!
  int count = 0; 
  public int increment() { 
    count++; 
    return count; 
  } 
%>
<html>
<head>
  <title>Hello JSP</title>
</head>
<body>
  <h1>欢迎来到 JSP 页面</h1>
  <p>
    <% 
        String message = "当前访问次数: " + increment(); 
        out.println(message); 
    %>
  </p>
  <p>服务器时间: <%= new java.util.Date() %></p>
</body>
</html>
```

---

### 9. Правила записи Java-кода внутри JSP. Стандартные переменные, доступные в скриптлетах и выражениях.

在 JSP 中编写 Java 代码的规则。小脚本和表达式中可用的标准变量。

在 JSP（JavaServer Pages）中编写 Java 代码时，有一些基本规则和标准变量可以使用。下面将详细介绍这些内容。

#### 编写 Java 代码的规则

1. 脚本块: Java 代码可以放在 <% %> 标签内，且可以包含任意有效的 Java 代码。

    ```jsp
    <% 
      // 这是一个脚本块

      int num = 5;

      out.println("数字是: " + num);

    %>
    ```
2. 表达式: 表达式使用 <%= %> 标签，结果会被自动输出到响应中。

    `<%= "当前时间: " + new java.util.Date() %>`

3. 声明: 可以使用 <%! %> 声明变量和方法。这是在页面级别定义的。

    ```jsp
    <%!

      int count = 0; 
      public int increment() { 
        count++; 
        return count; 
      }
    %>
    ```
4. 使用 Java API: 在 JSP 中可以使用 JDK 提供的标准 Java API，例如 String、ArrayList、Date 等。
5. 避免大量 Java 代码: 在 JSP 中应尽量避免将大量 Java 代码直接嵌入到 HTML 中，推荐使用 Java Beans、Servlets 或 MVC 模式来分离视图和控制逻辑。

#### 小脚本和表达式中可用的标准变量

在 JSP 中，有一组标准变量和对象可以直接使用，这些变量与 HTTP 请求和响应相关，常见的标准变量包括：

1. request: 一个HttpServletRequest对象，包含客户端请求的信息。
    - `request.getParameter("paramName")` 获取请求参数。
2. response: 一个HttpServletResponse对象，用于生成响应。
    - `response.setContentType("text/html")` 设置内容类型。
3. out: 一个JSPWriter对象，通常使用out来输出内容到客户端。
    - `out.println("Hello, World!");` 输出文本。
4. session: 一个HttpSession对象，用于存储会话数据。
    - `session.setAttribute("username", "John")` 保存会话属性。
5. application: 一个ServletContext对象，用于存储全局数据。
    - `application.setAttribute("appName", "MyApp")` 设置应用程序范围的属性。
6. page: 当前 JSP 页面对象，通常使用较少。
    - `page.getClass().getName()` 获取当前页面类名。
7. config: 当前 JSP 配置对象（ServletConfig），包含 JSP 配置的信息。
    - `config.getServletName()` 获取当前 Servlet 名称。

#### 示例代码

```jsp
<%@ page contentType="text/html; charset=UTF-8" language="java" %>
<html>
<head>
  <title>JSP 示例</title>
</head>
<body>
  <h1>欢迎来到 JSP 页面</h1>
  <p>请求参数: <%= request.getParameter("paramName") != null ? request.getParameter("paramName") : "没有参数提供" %></p>
  <p>服务器时间: <%= new java.util.Date() %></p>

  <%
    String userName = (String) session.getAttribute("username");

    if (userName == null) {
      userName = "访客";
    }
  %>

  <p>欢迎, <%= userName %>!</p>

  <% 
    out.println("这是使用 out 对象输出的内容。"); 
  %>

</body>
</html>
```

---

### 10. Bean-компоненты и их использование в JSP.

JavaBeans 是一种用于封装多个对象到一个单一对象中的规范，使得操作更为简单。在 JSP（JavaServer Pages）中，JavaBeans 被广泛使用，因为它们可以方便地以属性的形式访问和管理数据。使用 JavaBeans 使得 JSP 页面与 Java 代码的分离更加清晰，有助于实现 MVC（Model-View-Controller）设计模式。

#### JavaBean 的基本特征

1. 可序列化: JavaBean 通常实现 Serializable 接口，以便在网络上进行传输或存储。
2. 公共无参构造函数: JavaBean 需要有一个公共的无参构造函数，以便在构建时创建实例。
3. 私有属性: Bean 的属性应该是私有的，以确保数据的封装性。
4. 公共 getter 和 setter 方法: 通过公开的 getter 和 setter 方法访问和修改属性。

#### JavaBean 示例

以下是一个简单的 JavaBean 示例，表示用户信息：

```java
package com.example;
import java.io.Serializable;

public class User implements Serializable {
  private String name;
  private int age;
  // 无参构造函数

  public User() {
  }

  // Getter 和 Setter 方法

  public String getName() {
    return name;

  }

  public void setName(String name) {
    [this.name](http://this.name) = name;

  }

  public int getAge() {
    return age;
  }

  public void setAge(int age) {
    this.age = age;
  }
}
```

#### 在 JSP 中使用 JavaBean

在 JSP 页面中使用 JavaBean，可以通过以下步骤实现：

1. 引入 JavaBean: 在 JSP 页面中使用 [jsp:useBean](jsp:useBean) 标签来引入一个 JavaBean。
2. 设置属性: 使用 [jsp:setProperty](jsp:setProperty) 标签来设置 JavaBean 的属性。
3. 获取属性: 使用 EL（表达式语言）或脚本表达式来获取 JavaBean 的属性。

#### JSP 示例

以下是一个 JSP 示例，展示了如何使用 JavaBean User：

```jsp
<%@ page contentType="text/html; charset=UTF-8" language="java" %>

<%@ taglib uri="[http://java.sun.com/jsp/jstl/core](http://java.sun.com/jsp/jstl/core)" prefix="c" %>

<%@ page import="com.example.User" %>

<html>

<head>

  <title>JSP 使用 JavaBean 示例</title>

</head>

<body>

  <h1>用户信息</h1>

  <!-- 创建 User JavaBean 实例 -->

  <jsp:useBean id="user" class="com.example.User" scope="session" />

  <!-- 设置用户属性 -->

  <jsp:setProperty name="user" property="name" value="John Doe" />

  <jsp:setProperty name="user" property="age" value="30" />

  <h2>欢迎, <%= user.getName() %>!</h2>

  <p>年龄: <%= user.getAge() %> 岁</p>

  <!-- 使用 EL 获取属性 -->

  <h3>欢迎, ${[user.name](http://user.name)}!</h3>

  <p>年龄: ${user.age} 岁</p>

</body>

</html>
```

#### 解释代码

1. [jsp:useBean: 创建一个 User 对象，作用域为 session。](jsp:useBean: 创建一个 User 对象，作用域为 session。)
2. [jsp:setProperty: 设置 User 对象的 name 和 age 属性。](jsp:setProperty: 设置 User 对象的 name 和 age 属性。)
3. user.getName() 和 user.getAge(): 使用脚本表达式获取 JavaBean 属性并输出。
4. ${[user.name](http://user.name)} 和 ${user.age}: 使用表达式语言（EL）来获取 JavaBean 属性的值，提供了更简洁的方式。

#### 总结

在 JSP 中使用 JavaBeans 可以有效地分离业务逻辑和表示层，促进代码的重用和维护性。通过封装数据，使用 JavaBeans 能够提高 JSP 的可读性和可维护性，同时也符合 MVC 架构设计的原则。

---

### 11. Стандартные теги JSP. Использование Expression Language (EL) в JSP.

在 JSP（JavaServer Pages）中，标准 JSP 标签和表达式语言（EL）是用于简化动态内容生成的重要工具。标准标签使得 JSP 页面可以更容易地与 Java 代码进行交互，而 EL 提供了一种简洁的方式来访问和操作数据。

#### 标准 JSP 标签

标准 JSP 标签主要包括以下几类：

1. 文档标签: 用于包含或排除内容。
    - jsp:include: 将其他 JSP 文件或资源包括到当前 JSP 文件中。
    - jsp:forward: 将请求转发到另一个资源。
2. JavaBean 标签: 用于管理 JavaBeans。
    - jsp:useBean: 声明并实例化一个 JavaBean。
    - jsp:getProperty: 获取 JavaBean 的属性值并输出。
    - jsp:setProperty: 设置 JavaBean 的属性值。
3. 条件和循环标签: 与 JSTL（JavaServer Pages Standard Tag Library）一起使用。
    - <c:if>: 根据条件执行特定的代码块。
    - <c:choose>: 类似于 switch 的条件选择。
    - <c:forEach>: 迭代一个集合。

#### 引入 JavaBean 和标准标签示例

<%@ page contentType="text/html; charset=UTF-8" language="java" %>
<%@ taglib uri="[http://java.sun.com/jsp/jstl/core](http://java.sun.com/jsp/jstl/core)" prefix="c" %>
<%@ page import="com.example.User" %>

```jsp
<html>
<head>
  <title>使用标准 JSP 标签</title>
</head>
<body>
  <h1>用户详情</h1>
  <!-- 创建 User JavaBean 实例 -->
  <jsp:useBean id="user" class="com.example.User" scope="session" />
  <!-- 设置用户属性 -->
  <jsp:setProperty name="user" property="name" value="Jane Doe" />
  <jsp:setProperty name="user" property="age" value="25" />
  <!-- 获取用户属性 -->
  <h2>欢迎, <jsp:getProperty name="user" property="name" />!</h2>
  <p>年龄: <jsp:getProperty name="user" property="age" /> 岁</p>

  <!-- 使用 JSTL 标签 -->

  <c:if test="${user.age > 18}">
    <p>您是成年人。</p>
  </c:if>

  <c:if test="${user.age <= 18}">
    <p>您是未成年人。</p>
  </c:if>

</body>
</html>
```

#### 表达式语言 (EL)

表达式语言（EL）是一种用于访问和操作 JSP 中数据的简洁语法。EL 允许我们在 JSP 页面中简洁地引用 Java 对象属性、集合等，而不需要使用复杂的 Java 代码。EL 主要支持以下几种操作：

1. 对象属性访问: 可以通过点（.）符号访问对象的属性。
    - 例如，${user.name} 会获取 user 对象的 name 属性。
2. 集合和数组访问: 可以访问列表、数组和映射。
    - 例如，如果有一个 List 叫 userList，可以使用 ${userList[0]} 访问第一个元素。
3. 运算符: 支持条件表达式和运算符。
    - 例如，${user.age > 18} 可以用来检查年龄。
4. 常量和函数: 可以使用特定的常量和函数，如 empty 检查。
    - 例如，${empty userList} 可以检查 userList 是否为空。

#### EL 示例

以下是一个使用 EL 在 JSP 中获取数据的示例：

```jsp
<%@ page contentType="text/html; charset=UTF-8" language="java" %>

<%@ taglib uri="[http://java.sun.com/jsp/jstl/core](http://java.sun.com/jsp/jstl/core)" prefix="c" %>

<html>
<head>
  <title>表达式语言示例</title>
</head>

<body>
  <h1>用户列表</h1>
  <c:forEach var="user" items="${userList}">
    <p>欢迎, ${[user.name](http://user.name)}！您年龄: ${user.age} 岁。</p>
  </c:forEach>

  <c:if test="${not empty userList}">
    <p>用户列表不为空。</p>
  </c:if>

</body>
</html>
```

---

### 12. Параметры конфигурации JSP в дескрипторе развёртывания веб-приложения.

Web 应用程序部署描述符中的 JSP 配置选项

在 Java EE（现在称为 Jakarta EE）环境中，Web 应用程序的部署描述符通常是一个名为 "web.xml" 的 XML 文件。这个文件定义了 Web 应用的各种配置选项，包括 JSP 配置、Servlet、过滤器及其它资源的配置。

以下是一些与 JSP 配置相关的选项：

#### 1. JSP 文件的映射

在 web.xml 中，可以使用 <servlet> 和 <servlet-mapping> 标签来定义 JSP 文件的访问路径。例如，您可以将一个 JSP 文件映射到一个特定的 URL 模式：

```xml
<servlet>
  <servlet-name>exampleJSP</servlet-name>
  <jsp-file>/example.jsp</jsp-file>
</servlet>

<servlet-mapping>
  <servlet-name>exampleJSP</servlet-name>
  <url-pattern>/example</url-pattern>
</servlet-mapping>
```

在这个示例中，请求 /example 将被转发到 example.jsp。

#### 2. JSP 预编译选项

在某些情况下，您可能希望负责某些 JSP 文件的预编译，以提高性能。这可以通过以下方式进行配置，但通常更多地依赖于应用服务器的配置。

#### 3. JSP 错误处理

可以定义 JSP 的错误处理页面，通过 <error-page> 标签来指定当 JSP 文件出现异常时要转发到的错误页面：

```xml
<error-page>
  <exception-type>java.lang.Exception</exception-type>
  <location>/error.jsp</location>
</error-page>
```

在这个示例中，任何未处理的异常都将被转发到 error.jsp 页面。

#### 4. 会话和上下文参数

可以在 web.xml 中定义上下文参数（context params），这些参数可以在 JSP 文件中使用。例如：

```xml
<context-param>
  <param-name>configFilePath</param-name>
  <param-value>/WEB-INF/config.properties</param-value>
</context-param>
```

在 JSP 中，可以使用以下方式访问这些参数：

```jsp
<%
  String configFilePath = application.getInitParameter("configFilePath");
%>
```


#### 5. 过滤器和拦截

您还可以定义过滤器来对请求和响应进行预处理，例如，在 JSP 文件之前或之后进行某些处理。示例如下：

```xml
<filter>
  <filter-name>MyFilter</filter-name>
  <filter-class>com.example.MyFilter</filter-class>
</filter>

<filter-mapping>
  <filter-name>MyFilter</filter-name>
  <url-pattern>/*</url-pattern>
</filter-mapping>
```

在这个场景中，MyFilter 会应用于所有请求，包括对 JSP 文件的请求。

在 web.xml 文件中，可以配置许多与 JSP 相关的选项，帮助更好地控制 Web 应用的行为。

虽然随着 Java EE 标准的演进，许多配置已经可以通过注解代替，但了解 web.xml 的配置仍然是非常重要的，尤其是在处理复杂的应用程序时。

---

### 13. Шаблоны проектирования и архитектурные шаблоны. Использование в веб-приложениях.

设计模式和架构模式。在网络应用程序中使用

设计模式和架构模式是软件开发中非常重要的概念，尤其是在构建复杂的网络应用程序时。它们可以帮助开发者解决常见的问题，提高代码的可维护性、可扩展性和重用性。

#### 设计模式

设计模式是针对特定问题的解决方案，通常用于类和对象的设计中。以下是一些常见的设计模式及其在网络应用程序中的应用：

1. 单例模式 (Singleton Pattern)  

    确保一个类只有一个实例，并提供全局访问点。  

    应用示例：数据库连接池在大多数情况下使用单例模式，确保只有一个数据库连接池实例供整个应用程序使用。
2. 工厂模式 (Factory Pattern)  

    定义一个创建对象的接口，但由子类决定实例化哪一个类。  

    应用示例：在 Web 应用中，可以用工厂模式创建不同类型的用户对象（如普通用户、管理员用户），根据需求返回不同的实例。
3. 观察者模式 (Observer Pattern)  

    当一个对象的状态发生变化时，会通知其他依赖对象。  

    应用示例：适用于事件驱动的 Web 应用，例如实时聊天应用，当某个用户发送消息时，所有配置为接收通知的用户将会收到该消息。
4. 策略模式 (Strategy Pattern)  

    定义一系列算法，将每个算法封装起来，使它们可以互换。  

    应用示例：在网络应用中，可以根据不同条件选择不同的认证策略（如基本认证、OAuth 认证等）。
5. 适配器模式 (Adapter Pattern)  

    将一个类的接口转换成客户希望的另一个接口。  

    应用示例：在集成第三方服务时，使用适配器模式将外部 API 接口转换为应用内部所需要的格式。

#### 架构模式

架构模式则涉及更高层次的结构设计，用于指导整个系统的构建方式。以下是一些常见的架构模式及其在网络应用程序中的应用：

1. MVC 模式 (Model-View-Controller)  

    分离应用程序的表示层、业务逻辑层和数据访问层。  

    应用示例：在 Web 应用中，使用 MVC 模式将用户输入（控制器）、业务逻辑（模型）和输出呈现（视图）解耦。
2. 微服务架构 (Microservices Architecture)  

    将应用程序划分为一组小的、自治的服务，每个服务负责特定的功能。  

    应用示例：电商平台可以将用户服务、订单服务、支付服务拆分成独立的微服务，方便不同团队并行开发和维护。
3. 服务导向架构 (Service-Oriented Architecture, SOA)  

    强调服务之间的相互作用，使用消息传递进行服务通信。  

    应用示例：企业应用程序通过服务调用（如 RESTful API 或 SOAP）进行交互，增强了系统的集成能力。
4. 事件驱动架构 (Event-Driven Architecture)  

    通过事件通知机制实现系统组件间的解耦。  

    应用示例：在实时应用中，用户操作（如下单、支付）生成事件，其他组件监听这些事件并作出反应。
5. 单体架构 (Monolithic Architecture)  

    将所有功能集中在一个单一的代码库中，适用于小型应用。  

    应用示例：小型 Web 应用或初创项目可能会使用单体架构以较低的复杂性启动。

---

### 14. Архитектура веб-приложений. Шаблон MVC. Архитектурные модели Model 1 и Model 2 и их реализация на платформе Java EE.

Web 应用程序架构。MVC 模式。模型 1 和模型 2 架构模型及其在 Java EE 平台上的实现。

Web 应用程序架构中，MVC（模型-视图-控制器）模式是一种广泛应用的设计模式，可以帮助实现应用程序的分层结构，从而提高可维护性和可扩展性。在 MVC 模式中，应用程序分为三个基本部分：

1. 模型 (Model)：负责处理数据和业务逻辑。它代表应用程序的核心和状态，可以与数据库交互，处理与数据相关的操作。
2. 视图 (View)：负责呈现数据，并将用户界面（UI）输出给用户。视图直接与用户交互，但不应包含任何业务逻辑。
3. 控制器 (Controller)：充当模型与视图之间的桥梁，接收用户输入并根据需要更新模型或视图。它处理用户的请求并确定要调用的模型和视图。

#### MVC 架构模型 1 和 2

MVC 模式的实现有多种方式，其中最常见的两种是模型 1 和模型 2：

#### 模型 1

模型 1 是一种简单的实现方式，通常用于小型或简单的 Web 应用程序。在模型 1 中，视图和控制器的功能被紧密结合在一起。这意味着视图层直接处理请求并调用模型。其特点如下：

- 直接关联：请求被直接发送到 JSP（Java Server Pages），JSP 中包含业务逻辑，例如从模型获取数据，然后将数据展示到页面上。
- 开发快速：由于结构简单，开发过程较快，但随着系统的增大，代码可维护性较低。

实现示例：


```jsp
<%@ page import="com.example.model.User" %>
<%@ page import="com.example.service.UserService" %>
<%
  UserService userService = new UserService();
  List<User> users = userService.getAllUsers();
%>

<html>
<body>
  <h1>User List</h1>
  <ul>
    <%for (User user : users) { %>
      <li><%= user.getName() %></li>
    <%}%>
  </ul>

</body>

</html>
```

#### 模型 2

模型 2 是一种更为复杂的实现方式，通常用于大型和复杂的 Web 应用程序。在模型 2 中，控制器和视图是分开的，用户请求首先被发送到控制器，由控制器处理请求，然后根据用户的操作选择合适的视图和模型。其特点如下：

- 最佳实践：将控制器、模型和视图分开，增强了分离关注点（Separation of Concerns）。
- 可维护性高：使得代码更容易维护和扩展。

实现示例：

- 控制器 (Servlet)：

    ```java
    @WebServlet("/UserController")

    public class UserController extends HttpServlet {

        protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            UserService userService = new UserService();
            List<User> users = userService.getAllUsers();
            request.setAttribute("users", users);
            RequestDispatcher dispatcher = request.getRequestDispatcher("userList.jsp");
            dispatcher.forward(request, response);
        }
    }
    ```
- 视图 (JSP)：

    ```jsp
    <%@ page contentType="text/html;charset=UTF-8" language="java" %>
    <%@ taglib uri="[http://java.sun.com/jsp/jstl/core](http://java.sun.com/jsp/jstl/core)" prefix="c" %>
    <html>
    <body>
      <h1>User List</h1>
      <ul>
        <c:forEach var="user" items="${users}">
          <li>${[user.name](http://user.name)}</li>
        </c:forEach>
      </ul>

    </body>
    </html>
    ```

#### Java EE 平台上的实现

在 Java EE 平台上，MVC 模式通常通过以下技术实现：

- Servlets：作为控制器，处理用户请求并调用模型和视图。
- JSP 或 JSF (JavaServer Faces)：作为视图，负责显示内容并与用户交互。
- EJB (Enterprise JavaBeans) 或 JPA (Java Persistence API)：作为模型，处理业务逻辑和数据访问操作。

Java EE 还提供了一些框架（如 Spring MVC、JSF）来简化 MVC 模式的实现。这些框架提供了额外的功能，使得开发和维护变得更加简单。

MVC 模式通过将应用程序分为模型、视图和控制器三个部分，帮助提高代码的组织结构和可维护性。在 Java EE 平台上，模型 1 和模型 2 的实现各有优劣，开发者可以根据应用程序的规模和复杂性选择适合的架构。模型 2 更适用于大规模的应用，而模型 1 适合快速开发简单的应用。