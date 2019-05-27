package _001_705_DesignHashSet;

/*
 * Note:
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 * 
 * 
 * Author: icydragoon
 * Items PerBucket is set to 1001 to deal with the edge case 
 * when the key is 0 even though the description specify 
 * the number value ranges from 1-100k. 
 * This will occupy 1000 additional booleans in memory.
 * 
 * table_style = [
    [0, 1000, 10000, ..., 1000000],
    [1, 1001, 10001, ..., 0],
    .
    .
    [999, 1999, 19999, ..., 0]
]
 * 
 */

public class Solutions {

	public static void main(String[] args) {
		Solutions mhs = new Solutions();
		mhs.add(23);
		mhs.contains(23);
		mhs.remove(23);
	}

	private int buckets = 1000;
	private int itemsPerBucket = 1001;
	private boolean[][] table;

	/** Initialize your data structure here. */
	public Solutions() {
		table = new boolean[buckets][];
	}

	public int hash(int key) {
		return key % buckets;
	}

	public int pos(int key) {
		return key / buckets;
	}

	public void add(int key) {
		int hashkey = hash(key);

		if (table[hashkey] == null) {
			table[hashkey] = new boolean[itemsPerBucket];
		}
		table[hashkey][pos(key)] = true;
	}

	public void remove(int key) {
		int hashkey = hash(key);

		if (table[hashkey] != null)
			table[hashkey][pos(key)] = false;
	}

	/** Returns true if this set did not already contain the specified element */
	public boolean contains(int key) {
		int hashkey = hash(key);
		return table[hashkey] != null && table[hashkey][pos(key)];
	}
}
