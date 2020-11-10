class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegrees=[0]*numCourses
        graph={}
        
        for relation in prerequisites:
            #b->a
            a,b=relation[0],relation[1]
            indegrees[a]+=1
            
            node_list=[]
            if b not in graph:
                node_list.append(a)
                graph[b]=node_list
            else:
                node_list=graph[b]
                node_list.append(a)
                graph[b]=node_list
                
        queue=[]
        
        for i in range(numCourses):
            if indegrees[i]==0:
                queue.append(i)
                
        res=[]
        
        while len(queue)>0:
            cur=queue.pop(0)
            res.append(cur)
            
            if cur in graph:
                neighs=graph[cur]
                for neigh in neighs:
                    indegrees[neigh]-=1
                    if indegrees[neigh]==0:
                        queue.append(neigh)
                        
        if len(res)==numCourses:
            return res
        
        return []
