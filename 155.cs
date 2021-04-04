public class MinStack {
    
    int size, lowestIdx;
    int[] array;
    int[] lowest;
    
    /** initialize your data structure here. */
    public MinStack() {
        this.array = new int[35000];
        this.lowest = new int[35000];
        this.size = 0;
        this.lowestIdx = 1;
        lowest[0] = Int32.MaxValue;
    }
    
    public void Push(int val) {
        
        array[size] = val;
        size++;
        
        if(val<=lowest[lowestIdx-1]){
            lowest[lowestIdx] = val;
            lowestIdx++;
        }
    }
    
    public void Pop() {
        
        if(lowest[lowestIdx-1]==array[size-1])
            lowestIdx--;
        
        size--;
    }
    
    public int Top() {
        return array[size-1]; 
    }
    
    public int GetMin() {
        return lowest[lowestIdx-1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(val);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */