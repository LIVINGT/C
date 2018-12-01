#include<gstreamer-1.0/gst/gst.h>
#include<gstreamer-1.0/gst/gstmessage.h>
#include<gstreamer-1.0/gst/gstbus.h>
#include<gstreamer-1.0/gst/gstelement.h>


int main(int argc,char* argv[]){
    GstElement *pipeline,*source, *sink;
    GstBus* bus;
    GstMessage* msg;
    GstStateChangeReturn ret;

    //初始化
    gst_init(&argc,&argv);

    //构建元素
    source = gst_element_factory_make("videotestsrc","source");
    sink = gst_element_factory_make("autovideosink","sink");

    //构建空管道
    pipeline = gst_pipeline_new("test_pipeline");

    if (!pipeline || !source || !sink){
        g_printerr("没有元素被创建");
        return -1;
    }

    //构建这个管道
    gst_bin_add_many(GST_BIN(pipeline),source,sink,NULL);
    if(gst_element_link(source,sink) != TRUE){
        g_printerr("元素没有连接");
        return -1;
    }

    g_object_set(source,"pattern",0,NULL);

    //开始播放
    ret = gst_element_set_state(pipeline,GST_STATE_PLAYING);
    if(ret == GST_STATE_CHANGE_FAILURE){
        g_printerr("不能够播放");
        return -1;
    }

    //等到播放结束或者发生错误
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus,GST_CLOCK_TIME_NONE,GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    //解析消息
    if(msg!= NULL){
        GError* error;
        gchar *debug_info;
        switch(GST_MESSAGE_TYPE(msg)){
            case GST_MESSAGE_ERROR:
                gst_message_parse_error(msg,&error,&debug_info);
                g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (msg->src), error->message);
                g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
                g_clear_error (&error);
                g_free (debug_info);
                break;
            case GST_MESSAGE_EOS:
                g_printerr("到达视频流EOS\n");
                break;
            default:
                g_printerr("无法解析\n");
                break;

        }
        gst_message_unref(msg);

    }

    //释放资源
    gst_object_unref(bus);
    gst_element_set_state(pipeline,GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;

}
