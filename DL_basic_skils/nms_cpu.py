import numpy as np
def compute_nms(dets,thresh):
    x1=dets[:,0]
    y1=dets[:,1]
    x2=dets[:,2]
    y2=dets[:,3]

    scores=dets[:,5]
    areas=(x2-x1+1)*(y2-y1+1)
    indexes=np.argsort(scores)#sort according to sacores

    isSuppressed=np.zeros_like(indexes)#indicating whether this detection has been removed
    res=[]
    for i in indexes:
        if isSuppressed[i]:
            continue
        res.append(i)
        for j in range(i+1,len(indexes)):
            if isSuppressed[j]==1:
                continue
            #compute IOU
            m_x1 = max(x1[i], x1[j])
            m_x2 = min(x2[i], x2[j])
            m_y1 = max(y1[i], y1[j])
            m_y2 = max(y2[i],y2[j])
            inter_area=max(0,(m_x2-m_x1+1)*(m_y2-m_y1+1))
            IOU=inter_area/(areas[i]+areas[j]-inter_area)

            if IOU>thresh:
                isSuppressed[j]=1

    return res
