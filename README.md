**What are pointers?**

In `C` and `C++`, pointers are variables that store memory addresses as their values. They are a fundamental concept in both languages and are used extensively for tasks like dynamic memory allocation, working with arrays, and passing data by reference. 

**Syntax**

<table>
<tr>
    <th>Code</th>
    <th>[How you should read it][1]</th>
    <th>Comments</th>
</tr>
<tr>
    <td><code>int *px = &x</code></td>
    <td>Integer pointer named <code>px</code> is set to the address of <code>x</code>. By "integer pointer", we mean that this pointer points to an address whose stored value is an integer.</td>
    <td>This syntax is used to initialize the pointer variable. This is the unique situation that <code>*</code> reads "pointer". In all others, <code>*</code> will denote the dereference process.</td>
</tr>
<tr>
    <td><code>*px = 5</code></td>
    <td>The stored value pointed by <code>px</code> is set to <code>5</code>.</td>
    <td>This process is called "dereference", and it is used to assign the new value to a variable that is out of the scope in question.</td>
</tr>
<tr>
    <td><code>int y = *px</code></td>
    <td>Integer named <code>y</code> is set to the stored value pointed by <code>px</code>.</td>
    <td>It is also a dereference, but in the other way around, that is, the value of a variable that is out of the scope in question is assigned to a local variable.</td>
</tr>
<tr>
    <td><code>px->age = 5</code></td>
    <td>Second line: The struct's feild (or member) that <code>p</code> points to is set to <code>5</code>.</td>
    <td>In this case, the pointer <code>p</code> is a structure pointer, e.g., <code>struct Person *p = &mike<code></td>
</tr>
</table>

See examples.

[1]: https://www.youtube.com/watch?v=2ybLD6_2gKM&ab_channel=LowLevelLearning
