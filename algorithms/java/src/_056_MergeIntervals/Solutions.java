package _055_056_MergeIntervals;

import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class Solutions {
	public static void main(String[] args) {
		SolutionSorting so = new SolutionSorting();
		Interval i1 = new Interval(0, 5);
		Interval i2 = new Interval(3, 8);
		Interval i3 = new Interval(1, 9);

		List<Interval> intervals = new LinkedList<Interval>();
		intervals.add(i1);
		intervals.add(i2);
		intervals.add(i3);

		List<Interval> merged = so.merge(intervals);

		System.out.println(merged);

		for (Interval i : merged) {
			System.out.println(i.start);
			System.out.println(i.end);
		}
	}
}

class Solution {

}

class SolutionSorting {
	private class IntervalComparator implements Comparator<Interval> {
		@Override
		public int compare(Interval a, Interval b) {
			
			int flag =  a.start < b.start ? -1 : a.start == b.start ? 0 : 1;
			System.out.println(flag);
			return flag;
		}
	}

	public List<Interval> merge(List<Interval> intervals) {
		Collections.sort(intervals, new IntervalComparator());
		System.out.println();
		

		for (Interval i : intervals) {
			System.out.println(i.start);
			System.out.println(i.end);
		}

		LinkedList<Interval> merged = new LinkedList<Interval>();
		for (Interval interval : intervals) {
			// if the list of merged intervals is empty or if the current
			// interval does not overlap with the previous, simply append it.
			if (merged.isEmpty() || merged.getLast().end < interval.start) {
				merged.add(interval);
			}
			// otherwise, there is overlap, so we merge the current and previous
			// intervals.
			else {
				merged.getLast().end = Math.max(merged.getLast().end, interval.end);
			}
		}
		return merged;
	}
}

class Interval {
	public int start;
	public int end;

	Interval(int start, int end) {
		this.start = start;
		this.end = end;
	}

}