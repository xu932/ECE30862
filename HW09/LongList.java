public class LongList implements MyList {
    private long data;
    private LongList next;

    public LongList (int n) {
        this.data = n;
        this.next = null;
    }

    public LongList(LongList l, int n) {
        this.data = n;
        this.next = l;
    }

    public long getData() {
        return this.data;
    }

    public MyList next() {
        return this.next;
    }

    public void printNode() {
        System.out.print("LongList Node, data is: " + this.data);
    }
}