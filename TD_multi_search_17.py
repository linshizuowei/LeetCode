"""
给定一个较长字符串big和一个包含较短字符串的数组smalls，设计一个方法，根据smalls中的每一个较短字符串，对big进行搜索。输出smalls中的字符串在big里出现的所有位置positions，其中positions[i]为smalls[i]出现的所有位置。

示例：

输入：
big = "mississippi"
smalls = ["is","ppi","hi","sis","i","ssippi"]
输出： [[1,4],[8],[],[3],[1,4,7,10],[5]]
提示：

0 <= len(big) <= 1000
0 <= len(smalls[i]) <= 1000
smalls的总字符数不会超过 100000。
你可以认为smalls中没有重复字符串。
所有出现的字符均为英文小写字母。

"""

































class Solution:
    def multiSearch(self, big, smalls):
        c2id = {}
        for idx, c in enumerate(big):
            if c not in c2id:
                c2id[c] = []
            c2id[c].append(idx)

        ret = []
        for it in smalls:
            tmp = []
            fc = it[0]
            if fc in c2id:
                for sid in c2id[fc]:
                    for cid in range(1, len(it)):
                        if sid+cid >= len(big) or it[cid] != big[sid+cid]:
                            break
                    else:
                        tmp.append(sid)
            ret.append(tmp)
        return ret


if __name__ == '__main__':
    so = Solution()
    big = 'misisissippi'
    smalls = ["isis","ppi","hi","sis","i","ssippi"]
    print(so.multiSearch(big, smalls))
