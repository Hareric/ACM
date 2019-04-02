public class MinStack {
    public Stack<Integer> originStack;
    public Stack<Integer> minStack;
    public MinStack() 
    {
        originStack = new Stack<Integer>();
        minStack = new Stack<Integer>();
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    public void push(int number) 
    {
        // write your code here
        if(originStack.isEmpty())
        {
            originStack.push(number);
            minStack.push(number);
            return;
        }
        originStack.push(number);
        if(minStack.peek()<number)
        {
            minStack.push(minStack.peek());
        }else
        {
            minStack.push(number);
        }
            
            
    }

    /*
     * @return: An integer
     */
    public int pop() {
        // write your code here
        minStack.pop();
        return originStack.pop();
    }

    /*
     * @return: An integer
     */
    public int min() {
        // write your code here
        return minStack.peek();
    }
}
