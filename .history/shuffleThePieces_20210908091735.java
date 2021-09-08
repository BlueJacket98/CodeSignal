// # def shuffleThePieces(arr, pieces):
// #     hashMap = {}
// #     for piece in pieces:
// #         firstNum = piece[0]
// #         if hashMap.get(firstNum) == None:
// #             hashMap[firstNum] = [piece]
// #         else:
// #             hashMap[firstNum].append(piece)
// #     global cnt
// #     cnt = 0
// #     def dfs(combine, remain):
// #         global cnt
// #         if remain == []:
// #             if combine == arr:
// #                 cnt += 1
// #             return
// #         requiredNum = remain[0]
// #         if hashMap.get(requiredNum) == None:
// #             return
// #         else:
// #             candidates = hashMap[requiredNum]
// #         for i in range(len(candidates)):
// #             candidate = candidates[i]
// #             if len(candidate) > len(remain) or candidate != remain[:len(candidate)]:
// #                 continue
// #             else:
// #                 hashMap[requiredNum].pop(i)
// #                 dfs(combine + candidate, remain[len(candidate):])
// #                 hashMap[requiredNum].insert(i, candidate)
    
// #     dfs([], arr)
// #     if cnt == 0:
// #         return False
// #     else:
// #         return True

// JAVA
boolean shuffleThePieces(int[] arr, int[][] pieces) {
    Map<Integer, Integer> map = new HashMap<>();
    
    for(int i=0;i<arr.length;i++){
        map.put(arr[i],i);
    }
    // System.out.println(map);
    int count = 0;
    for(int[] piece : pieces){
        if(piece.length > 1){
            for(int i=0;i<piece.length-1;i++){
                int piece1 = map.getOrDefault(piece[i+1], -2);
                int piece2 = map.getOrDefault(piece[i], -2)+1;
                if(piece2 != piece1 || piece1 < 0 || piece2 < 0) {
                    return false;
                }
            }
        }
        for(int x:piece){
            ++count;
            if(!map.containsKey(x) || count > arr.length) return false;
        }
    }
    if(count != arr.length) return false;
    return true;
}
