"""
249. 移位字符串分组
给定一个字符串，对该字符串可以进行 “移位” 的操作，也就是将字符串中每个字母都变为其在字母表中后续的字母，比如："abc" -> "bcd"。这样，我们可以持续进行 “移位” 操作，从而生成如下移位序列：

"abc" -> "bcd" -> ... -> "xyz"
给定一个包含仅小写字母字符串的列表，将该列表中所有满足 “移位” 操作规律的组合进行分组并返回。

 

示例：

输入：["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]
输出：
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
解释：可以认为字母表首尾相接，所以 'z' 的后续为 'a'，所以 ["az","ba"] 也满足 “移位” 操作规律。
"""
































class Solution:
    def groupStrings(self, strings):
        if not strings:
            return []
        
        ret = []
        visited = [0] * len(strings)
        for i in range(len(strings)):
            if visited[i]:
                continue
            word = strings[i]
            visited[i] = 1
            tmp = [word]
            for j in range(i+1, len(strings)):
                if visited[j]:
                    continue
                cword = strings[j]
                if len(word) != len(cword):
                    continue
                dis = ord(word[0]) - ord(cword[0])
                for k in range(1, len(word)):
                    cdis = ord(word[k]) - ord(cword[k])
                    rcdis = cdis
                    if dis > 0 and cdis < 0:
                        rcdis = cdis + 26
                    elif dis < 0 and cdis > 0:
                        rcdis = cdis - 26
                    if cdis != dis and rcdis != dis:
                        break
                else:
                    tmp.append(cword)
                    visited[j] = 1
            ret.append(tmp[:])
        return ret
            

    
if __name__ == '__main__':
    so = Solution()
    llist = ["abc", "bcd", "yza", "acef", "xyz", "az", "ba", "a", "z"]
#    llist = ["ab","ba"]
    llist = ["fpbnsbrkbcyzdmmmoisaa","cpjtwqcdwbldwwrryuclcngw","a","fnuqwejouqzrif","js","qcpr","zghmdiaqmfelr","iedda","l","dgwlvcyubde","lpt","qzq","zkddvitlk","xbogegswmad","mkndeyrh","llofdjckor","lebzshcb","firomjjlidqpsdeqyn","dclpiqbypjpfafukqmjnjg","lbpabjpcmkyivbtgdwhzlxa","wmalmuanxvjtgmerohskwil","yxgkdlwtkekavapflheieb","oraxvssurmzybmnzhw","ohecvkfe","kknecibjnq","wuxnoibr","gkxpnpbfvjm","lwpphufxw","sbs","txb","ilbqahdzgij","i","zvuur","yfglchzpledkq","eqdf","nw","aiplrzejplumda","d","huoybvhibgqibbwwdzhqhslb","rbnzendwnoklpyyyauemm"]
    llist = ["btesefoxwzyniqcmcnfkefmh","wqyfapfpcbgylx","qyc","ou","wzytlakxznvnbzhmssueariy","fpqj","eujrsivkpiwggyovh","uvugcskdeovrollommlrfg","c","jgonhtfocyzarr","ulskmmatqqznaylakd","ioaxrmawezhzyskoloakzsm","acjyexa","wwkwfbpz","hmljck","zmknduzvkmnjmreksgoat","jxgjvxt","jgqy","tqvtyvjiiqnud","pwrodsmgd","elgdshbvs","czechesrrzwdm","mjtb","gudgsuq","sfdgwnsodfgcfkxdlzhtm","vazxqy","uuiudznx","rtapvor","ciurlguqytbtsmeifiuetmg","kbiaccqjggpdqobqat","gdlkeqclzvwxoo","q","ghgsoewpqahdaxxayyxdrs","ndsabretyrfpphxeq","wgha","nqpkcrboqemesqydjjlvrizp","ye","dlp","ysahcrhredianz","ldocopyhgjixsamwmxpuopwr"]
    ret = so.groupStrings(llist)
    print(ret)
