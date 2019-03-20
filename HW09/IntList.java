public class IntList implements MyList {
    private int data;
    private IntList next;

    public IntList (int n) {
        this.data = n;
        this.next = null;
    }

    public IntList(IntList l, int n) {
        this.data = n;
        this.next = l;
    }

    public int getData() {
        return this.data;
    }

    public MyList next() {
        return this.next;
    }

    public void printNode() {
        System.out.print("IntList Node, data is: " + this.data);
    }
}