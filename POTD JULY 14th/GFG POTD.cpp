Implement two stacks in an array
void push1(int x)
    {
        // Check if there is space between top1 and top2.
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack Overflow: Cannot push element into stack1." << endl;
        }
    }

    // Function to push an integer into stack2.
    void push2(int x)
    {
        // Check if there is space between top1 and top2.
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack Overflow: Cannot push element into stack2." << endl;
        }
    }

    // Function to remove an element from the top of stack1.
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout << "Stack Underflow: Cannot pop element from stack1." << endl;
            return -1; // Return a default value indicating underflow.
        }
    }

    // Function to remove an element from the top of stack2.
    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            cout << "Stack Underflow: Cannot pop element from stack2." << endl;
            return -1; // Return a default value indicating underflow.
        }
    }
