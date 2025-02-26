
import code.Allocator;

class AllocatorMain {

    public static void main(String[] args) {
        Allocator a = new Allocator(10);
        System.out.println(a.allocate(1, 1));
        System.out.println(a.allocate(1, 2));
        System.out.println(a.allocate(1, 3));
        System.out.println(a.freeMemory(2));
        System.out.println(a.allocate(3, 4));
        System.out.println(a.allocate(1, 1));
        System.out.println(a.allocate(1, 1));
        System.out.println(a.freeMemory(1));
        System.out.println(a.allocate(10, 2));
        System.out.println(a.freeMemory(7));
    }

}
