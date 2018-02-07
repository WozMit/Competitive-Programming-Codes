// Arup Guha
// 1/26/2014
// Solution to 2009 UCF Local Contest Problem: Polygon Restoration

import java.util.*;

public class polygon {

	public static int firstID;
	public static int secondID;
	public static int n;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int loop = 1;
		n = stdin.nextInt();

		// Go through each case.
		while (n != 0) {

			// Read in the points.
			pt[] list = new pt[n];
			for (int i=0; i<n; i++) {
				int x = stdin.nextInt();
				int y = stdin.nextInt();
				list[i] = new pt(i+1,x,y);
			}

			// Sort by y first.
			Arrays.sort(list);
			firstID = list[0].ID;
			secondID = list[1].ID;

			// Will store neighbors of vertices in the polygon.
			ArrayList[] neighbors = new ArrayList[n];
			for (int i=0; i<n; i++)
				neighbors[i] = new ArrayList<Integer>();

			// Get horizontal edges in the polygon.
			getHoriz(list, neighbors);

			// Sort by x, and get all vertical edges.
			Arrays.sort(list, new Comparator<pt>() { public int compare(pt a, pt b) { if (a.x != b.x) return a.x - b.x; return a.y - b.y;}});
			getVert(list, neighbors);

			// Run our algorithm - a dfs from the starting vertex going horizontal.
			int[] order = solve(list, neighbors);

			// Output the solution.
			System.out.print("Polygon #"+loop+": ");
			for (int i=0; i<order.length; i++)
				System.out.print(order[i]+" ");
			System.out.println();

			// Get next case.
			n = stdin.nextInt();
			loop++;
		}
	}

	// Precond: Sorted by y then x...
	public static void getHoriz(pt[] list, ArrayList[] neighbors) {

		int i = 0, n = list.length;
		int curY = list[i].y;

		// Go through list.
		while (i < n) {

			// Grab pairs at the same y level.
			while (i < n && list[i].y == curY) {
				neighbors[list[i].ID-1].add(list[i+1].ID-1);
				neighbors[list[i+1].ID-1].add(list[i].ID-1);
				i += 2;
			}

			// Update current y.
			if (i < n) curY = list[i].y;
		}
	}

	public static void getVert(pt[] list, ArrayList[] neighbors) {

		int i = 0, n = list.length;
		int curX = list[i].x;

		// Go through list.
		while (i < n) {

			// Grab pairs at the same x level.
			while (i < n && list[i].x == curX) {
				neighbors[list[i].ID-1].add(list[i+1].ID-1);
				neighbors[list[i+1].ID-1].add(list[i].ID-1);
				i += 2;
			}

			// Update current x.
			if (i < n) curX = list[i].x;
		}
	}

	public static int[] solve(pt[] list, ArrayList[] neighbors) {

		// Set up search around polygon.
		int[] ans = new int[n];
		ans[0] = firstID;
		ans[1] = secondID;
		boolean[] used = new boolean[n];
		used[firstID-1] = true;
		used[secondID-1] = true;

		// Fill in the rest of the vertices.
		for (int i=2; i<n; i++) {

			int curVert = ans[i-1] - 1;

			// Find unused neighbor to the current vertex. There is guaranteed to be exactly 1.
			for (int j=0; j<neighbors.length; j++) {

				int next = (Integer)neighbors[curVert].get(j);

				// We found it.
				if (!used[next]) {
					used[next] = true;
					ans[i] = next + 1;
					break;
				}
			}
		}

		// Here is our polygon!
		return ans;
	}


}

class pt implements Comparable<pt> {

	public int ID;
	public int x;
	public int y;

	public pt(int myID, int myx, int myy) {
		ID = myID;
		x = myx;
		y = myy;
	}

	public int compareTo(pt other) {
		if (this.y != other.y)
			return this.y - other.y;
		return this.x - other.x;
	}
}

class edge {

	public int v1;
	public int v2;

	public edge(int a, int b) {
		v1 = a;
		v2 = b;
	}

	public boolean connectsTo(edge other) {
		return this.v2 == other.v1;
	}
}