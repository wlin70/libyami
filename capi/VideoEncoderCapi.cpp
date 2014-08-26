#include "VideoEncoderCapi.h"
#include "VideoEncoderInterface.h"
#include "VideoEncoderHost.h"

using namespace YamiMediaCodec;

EncodeHandler createEncoder(const char *mimeType)
{
    return createVideoEncoder(mimeType);
}

void encodeSetNativeDisplay(EncodeHandler p, NativeDisplay * display)
{
    if(p) ((IVideoEncoder*)p)->setNativeDisplay(display);
}

Encode_Status encodeStart(EncodeHandler p)
{
    if(p) return ((IVideoEncoder*)p)->start();
    else return ENCODE_FAIL;
}

void encodeStop(EncodeHandler p)
{
    if(p) ((IVideoEncoder*)p)->stop();
}

Encode_Status encode(EncodeHandler p, VideoEncRawBuffer * inBuffer)
{
    if(p) return ((IVideoEncoder*)p)->encode(inBuffer);
    else return ENCODE_FAIL;
}

Encode_Status encodeGetOutput(EncodeHandler p, VideoEncOutputBuffer * outBuffer, bool withWait)
{
    if(p) return ((IVideoEncoder*)p)->getOutput(outBuffer, withWait);
    else return ENCODE_FAIL;
}

Encode_Status getParameters(EncodeHandler p, VideoParamConfigType type, Yami_PTR videoEncParams)
{
    if(p) return ((IVideoEncoder*)p)->getParameters(type, videoEncParams);
    else return ENCODE_FAIL;
}

Encode_Status setParameters(EncodeHandler p, VideoParamConfigType type, Yami_PTR videoEncParams)
{
    if(p) return ((IVideoEncoder*)p)->setParameters(type, videoEncParams);
    else return ENCODE_FAIL;
}

Encode_Status getMaxOutSize(EncodeHandler p, uint32_t * maxSize)
{
    if(p) return ((IVideoEncoder*)p)->getMaxOutSize(maxSize);
    else return ENCODE_FAIL;
}

Encode_Status getStatistics(EncodeHandler p, VideoStatistics * videoStat)
{
    if(p) return ((IVideoEncoder*)p)->getStatistics(videoStat);
    else return ENCODE_FAIL;
}

Encode_Status getConfig(EncodeHandler p, VideoParamConfigType type, Yami_PTR videoEncConfig)
{
    if(p) return ((IVideoEncoder*)p)->getConfig(type, videoEncConfig);
    else return ENCODE_FAIL;
}

Encode_Status setConfig(EncodeHandler p, VideoParamConfigType type, Yami_PTR videoEncConfig)
{
    if(p) return ((IVideoEncoder*)p)->setConfig(type, videoEncConfig);
    else return ENCODE_FAIL;
}

void releaseEncoder(EncodeHandler p)
{
    if(p) releaseVideoEncoder((IVideoEncoder*)p);
}