# RTMPose 关键点检测

## 环境配置
我的电脑是 Windows 系统，安装了 miniconda。 
不同项目需要不同的版本，使用 conda 更容易管理。 

首先来安装创建 RTMPose 的环境[^1]。

```
# 以下命令都在 minicoda shell 执行
# 查看所有环境
conda info -e

# 创建 RTMPose 环境
conda create -n RTMPose python=3.8

# 删除环境
# conda remove -n 环境名 --all 

# 切换到 RTMPose 环境
conda activate RTMPose

# 安装Pytorch
pip3 install install torch==1.10.1+cu113 torchvision==0.11.2+cu113 torchaudio==0.10.1+cu113 -f https://download.pytorch.org/whl/cu113/torch_stable.html

# 用 MIM 安装 MMCV
pip install -U openmim
mim install mmengine
mim install "mmcv>=2.0.0"
mim install "mmdet>=3.0.0rc6"

# 安装其它工具包
pip install opencv-python pillow matplotlib seaborn tqdm pycocotools -i https://pypi.tuna.tsinghua.edu.cn/simple

# 从 github 上下载最新的 mmpose 源代码
git clone https://github.com/open-mmlab/mmpose.git -b tutorial2023

# 进入主目录
cd mmpose

# 安装 MMPose 
mim install -e .

# <begin> 下载预训练模型权重文件和视频素材 -------------------------------------------
import os

# 创建 checkpoint 文件夹，用于存放预训练模型权重文件
mkdir checkpoint

# 创建 outputs 文件夹，用于存放预测结果
mkdir outputs

# 创建 data 文件夹，用于存放图片和视频素材
mkdir data
mkdir data\test

pip inatall wget
python
import wget


# 多人图片，来源：https://www.pexels.com/zh-cn/photo/2168292/
wget.download('https://zihao-openmmlab.obs.cn-east-3.myhuaweicloud.com/20220610-mmpose/images/multi-person.jpeg', out='data/test/multi-person.jpeg')

# 单人视频-唱跳篮球 
wget.download('https://zihao-openmmlab.obs.myhuaweicloud.com/20220610-mmpose/videos/cxk.mp4', out='data/test')


# 妈妈和女儿跳舞，经微信压缩
wget.download('https://zihao-openmmlab.obs.myhuaweicloud.com/20220610-mmpose/videos/mother_wx.mp4', out='data/test')

# 两个女生跳舞视频，来源：https://mixkit.co/free-stock-video/two-girls-having-fun-in-a-retro-restaurant-42298/

wget.download('https://zihao-openmmlab.obs.cn-east-3.myhuaweicloud.com/20220610-mmpose/videos/two-girls.mp4', out='data/test/two-girls.mp4')

# <end> 下载预训练模型权重文件和视频素材 -------------------------------------------

# <begin> 检查是否安装成功，没有报错，即证明安装成功。-------------------------------------------
# 检查 Pytorch [Pytorch 版本 1.10.1+cu113] [CUDA 是否可用 True]
import torch, torchvision
print('Pytorch 版本', torch.__version__)
print('CUDA 是否可用',torch.cuda.is_available())

# 检查 mmcv [MMCV版本 2.0.0] [CUDA版本 11.3] [编译器版本  MSVC 192829924]
import mmcv
from mmcv.ops import get_compiling_cuda_version, get_compiler_version
print('MMCV版本', mmcv.__version__)
print('CUDA版本', get_compiling_cuda_version())
print('编译器版本', get_compiler_version())

# 检查 mmpose [mmpose版本 1.0.0]
import mmpose
print('mmpose版本', mmpose.__version__)
# <end> 检查是否安装成功，没有报错，即证明安装成功。-------------------------------------------

# 一些包在上面安装 MMPose 的时候已经安装了，所以不用重复安装。下面是安装 MMDetection 的步骤

# 退出 python
quit()
cd..

# 下载 MMDetection
# git clone https://github.com/open-mmlab/mmdetection.git -b 3.x

# 进入主目录
cd mmdetection

# 安装 MMDetection
pip install -v -e .

# 下载预训练模型权重文件和视频素材
# 创建 checkpoint 文件夹，用于存放预训练模型权重文件
mkdir checkpoint

# 创建 outputs 文件夹，用于存放预测结果
mkdir outputs

# 创建 data 文件夹，用于存放图片和视频素材
mkdir data

# 检查 mmdetection [mmdetection 版本 3.0.0]
python
import mmdet
print('mmdetection版本', mmdet.__version__)

```

## MMPose 预训练模型预测

```
cd mmpose

# 预测单张图像
# HRNet
python demo/topdown_demo_with_mmdet.py demo/mmdetection_cfg/faster_rcnn_r50_fpn_coco.py https://download.openmmlab.com/mmdetection/v2.0/faster_rcnn/faster_rcnn_r50_fpn_1x_coco/faster_rcnn_r50_fpn_1x_coco_20200130-047c8118.pth configs/body_2d_keypoint/topdown_heatmap/coco/td-hm_hrnet-w32_8xb64-210e_coco-256x192.py https://download.openmmlab.com/mmpose/top_down/hrnet/hrnet_w32_coco_256x192-c78dce93_20200708.pth --input data/test/multi-person.jpeg --output-root outputs/B1_HRNet_1 --device cuda:0 --bbox-thr 0.5 --kpt-thr 0.2 --nms-thr 0.3 --radius 8 --thickness 4 --draw-bbox --draw-heatmap --show-kpt-idx

# RTMPose
python demo/topdown_demo_with_mmdet.py demo/mmdetection_cfg/faster_rcnn_r50_fpn_coco.py https://download.openmmlab.com/mmdetection/v2.0/faster_rcnn/faster_rcnn_r50_fpn_1x_coco/faster_rcnn_r50_fpn_1x_coco_20200130-047c8118.pth projects/rtmpose/rtmpose/body_2d_keypoint/rtmpose-s_8xb256-420e_coco-256x192.py https://download.openmmlab.com/mmpose/v1/projects/rtmpose/rtmpose-s_simcc-aic-coco_pt-aic-coco_420e-256x192-fcb2599b_20230126.pth --input data/test/multi-person.jpeg --output-root outputs/B1_RTM_1 --device cuda:0 --bbox-thr 0.5 --kpt-thr 0.5 --nms-thr 0.3 --radius 8 --thickness 4 --draw-bbox --draw-heatmap --show-kpt-idx

# 预测视频：--input 为视频路径
# HRNet
python demo/topdown_demo_with_mmdet.py demo/mmdetection_cfg/faster_rcnn_r50_fpn_coco.py https://download.openmmlab.com/mmdetection/v2.0/faster_rcnn/faster_rcnn_r50_fpn_1x_coco/faster_rcnn_r50_fpn_1x_coco_20200130-047c8118.pth configs/body_2d_keypoint/topdown_heatmap/coco/td-hm_hrnet-w32_8xb64-210e_coco-256x192.py  https://download.openmmlab.com/mmpose/top_down/hrnet/hrnet_w32_coco_256x192-c78dce93_20200708.pth  --input data/test/cxk.mp4 --output-root outputs/B1_HRNet_2 --device cuda:0  --bbox-thr 0.5 --kpt-thr 0.2  --nms-thr 0.3  --radius 5  --thickness 2  --draw-bbox   --draw-heatmap  --show-kpt-idx

# RTMPose
python demo/topdown_demo_with_mmdet.py demo/mmdetection_cfg/faster_rcnn_r50_fpn_coco.py https://download.openmmlab.com/mmdetection/v2.0/faster_rcnn/faster_rcnn_r50_fpn_1x_coco/faster_rcnn_r50_fpn_1x_coco_20200130-047c8118.pth projects/rtmpose/rtmpose/body_2d_keypoint/rtmpose-s_8xb256-420e_coco-256x192.py https://download.openmmlab.com/mmpose/v1/projects/rtmpose/rtmpose-s_simcc-aic-coco_pt-aic-coco_420e-256x192-fcb2599b_20230126.pth --input data/test/cxk.mp4 --output-root outputs/B1_RTM_2 --device cuda:0 --bbox-thr 0.5 --kpt-thr 0.5 --nms-thr 0.3 --radius 5 --thickness 2 --draw-bbox --draw-heatmap --show-kpt-idx


```

## 作业

```python
cd mmdetction

# 训练 rtmdet
python tools/train.py data/rtmdet_tiny_ear.py


```


## 参考资料

[^1]:[*合集·MMPose开源算法库教程*](https://space.bilibili.com/1900783/channel/collectiondetail?sid=1418092)

[^]:[**]()

[^]:[**]()

[^]:[**]()
