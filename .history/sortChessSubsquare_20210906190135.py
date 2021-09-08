# 第三题 sortChessSubsquare 是黑白棋盘sort，给一个 int[][] 棋盘 和一个 int[][] query, 每个query 会有 [x,y,w] 三个 数字，分别代表了 window 左上角的 x, y 和window 的长宽（长‍‌‌‌‌‌‌‌‍‍‌‍‌‍‍‌‌‍‌‌宽永远一样）你要做的是把这个window里面的数字按照 黑，白分别sort 然后放回棋盘
# 我是用了 两个 arrayList 分别记录了遇到的黑和白的数字，然后 collections.sort，感觉这里的关键点是 找规律， 黑子永远是 行列全部为奇数或者 偶数，知道这点应该就稳了

def sortChessSubsquare()