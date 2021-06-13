# encoding: utf-8
# 订阅主题
import paho.mqtt.client as mqtt


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("/test/server")


def on_message(client, userdata, msg):
    print(msg.topic+" " + ":" + str(msg.payload))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("42.193.228.185", 1883, 60)
client.loop_forever()