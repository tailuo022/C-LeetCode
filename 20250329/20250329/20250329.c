

//2360.

/*
给你一个 n 个节点的有向图，节点编号为 0 到 n - 1 ，
	其中每个节点 至多 有一条出边。 
图用一个大小为 n 下标从 0 开始的数组 edges 表示，
	节点 i 到节点 edges[i] 之间有一条有向边。
		如果节点 i 没有出边，那么 edges[i] == -1 。
请你返回图中的 最长 环，如果没有任何环，请返回 - 1 。
*/
               

#define MAX_N 100000
int color[MAX_N];
int depth_map[MAX_N];
int max_len;

void dfs(int u, int depth, int* edges) {
	color[u] = 1;
	depth_map[u] = depth;
	int v = edges[u];
	if (v != -1) {
		if (color[v] == 1) {
			int len_cycle = depth - depth_map[v] + 1;
			if (len_cycle > max_len) {
				max_len = len_cycle;
			}
		}
		else if (color[v] == 0) {
			dfs(v, depth + 1, edges);
		}
	}
	color[u] = 2;
}

int longestCycle(int* edges, int edgesSize) {
	memset(color, 0, sizeof(color));
	max_len = -1;
	for (int i = 0; i < edgesSize; i++) {
		if (color[i] == 0) {
			dfs(i, 0, edges);
		}
	}
	return max_len == -1 ? -1 : max_len;
}

/*
	环是起点和终点相同的玩意。
	构建辅助数组 color 和 depth_map 前者表示该节点的状态，
		0 表示还没有访问过，1 表示访问中，2 表示已经访问完了。
		depth_map 记录节点在访问途中的深度。
	在初始化每一个节点的状态为 0 (还没有访问过)之后，依次访问每一个节点。
		当节点为 0 状态时，对该节点调用深度优先算法。
	深度优先算法：
		某一个节点第一次调用该算法时，标记该节点的状态为 1 
			(访问中，即还没有到达这条路径的终点，也就是还没有形成环)，
			记录当前深度为 0 (因为是第一次调用，还不知道该节点有没有出度)。
		如果该节点指向了其他节点，并且被指向的节点的状态是 1 
			(实际上是被第二次访问，刚开始的 0 状态算初始化，没有被访问。
			也就是确定了环的头和环的尾，而环的头尾是同一个节点，代码表现在 1 状态下被访问，也就是形成了环)，记录当前环的长度。此时退出 if (v != -1)语句。将该节点的状态标记为2，表示已经确认在某一个环上了。
		如果状态是 0 ，调用一次dfs，该节点的可能深度在上一次调用的深度上加一
			(不知道有没有形成环，所以是可能的深度)。
	可能的疑问：
		 A：为什么环长计算公式是 depth - depth_map[v] + 1?
			数组 depth_map[v] 记录的是从起始节点到 v 的边数，当再次遇到 v 节点的时候，表示形成了环，
			假设是由 u 节点到 v 节点形成了环，所以环的长度就是起始节点到 v 的边长和起始节点到 u 的边长的差 + 1
			(形成环要封闭，所以要多一条)，记为 a - b + 1，
			其中 a 保存在 depth_map[v] 当中，b 记录在depth_map[u] 当中，也就是 depth 当中。
		 B：为什么不用在调用深度优先算法之前不用初始化 color 数组为初该节点以外的全 0 ？
			题目讲述每一个节点最多只有一条出度，也就是说并不会出现环中套环(环嵌套)的现象，
			也就是一个节点被标记为 2 后（已经是一个环的一部分）后序遇到他直接跳过就行了
			(不会出现包含这个节点的另外一个环，否则就是环嵌套)，
			而如果每次调用 dfs 前都要初始化，在 dfs 嵌套调用的时候就会出错，因为后续初始化的操作会导致数据丢失。
		 C：为什么使用全局变量？
			懒得传参了。

作者：tailuo022
链接：https://leetcode.cn/problems/longest-cycle-in-a-graph/solutions/3632400/dfsbian-li-mei-yi-ge-jie-dian-by-tailuo0-84cd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/