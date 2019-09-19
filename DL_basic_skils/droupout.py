
import numpy as np
def droupout_forward(x,droupout_param):
    """

    :param x: input data(any shape)
    :param droupout_param: dictionary with keys: (p,mode(test/train),seed)
    :return: (out,cache)
    """
    p,mode=droupout_param['p'],droupout_param['mode']

    if 'seed' in droupout_param:
        np.random.seed(droupout_param['seed'])
    mask=None
    out=None

    if mode=='train':
        mask=(np.random.rand(*x.shape)<p)/p#inverted droupout: normally p=0.5, scale all by p to avoid having to multiply by p on backpropagation.
        out=x*mask

    elif mode=='test':
        mask=None
        out=x# no using dropout when testing

    cache=(droupout_param,mask)#中间需要为反向传播缓存的主要是摩模型和掩码

    return out,cache


def droupout_backward(d_out,cache):

    droupout_param,mask=cache
    mode=droupout_param['mode']

    d_x=None

    if mode=="train":
        d_x=d_out*mask
    elif mode=='test':
        d_x=d_out
    return d_x
