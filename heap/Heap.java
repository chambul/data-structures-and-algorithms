public class Heap
{

  // what object memebers?

  // parents < children : helper methods
  //getLeftChild: index*2 + 1

  //getRightChild index*2 +1

  //getParent? (index-2)/2 ?

  //any other helper methods?? 

  //peek() -  return root element if there is.

  //poll() - remove root, put last into root, heapifyDown()

  // add() - add to last index, heapifyUp().

    public static void swap(int i1,int i2, int[] heap){
        int temp = heap[i1];
        heap[i1] = heap[i2];
        heap[i2] = temp;
    }

	public static void main(String[] args) {

		    int[] heap = new int[10];
		    heap[0] = 10;
		    heap[1] = 20;
		    swap(0,1,heap);

		System.out.println(heap[0] + "  "+ heap[1]);



	}
}
