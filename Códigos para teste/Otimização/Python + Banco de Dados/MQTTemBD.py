import paho.mqtt.client as mqtt
import pymysql

#Criando a conexão com o servidor do banco de dados
try:
    conexao = pymysql.connect(
        host='localhost',
        user='root',
        passwd='',
        database='telemetriabd'
    )
except:
    print("Não é possivel conectar ao servidor de banco de dados")

cursor = conexao.cursor()

# O retorno de chamada para quando o cliente receber uma resposta CONECTADO do servidor.
def on_connect(client, userdata, flags, rc):
    print("Conectado ao MQTT com QoS: "+str(rc))

    client.subscribe("test")

# O retorno de chamada para quando uma mensagem PUBLISH é recebida do servidor.
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

    # Instrução SQL
    com_sql = "INSERT INTO velocidade(valor) VALUES (%s)"

    valor = [
        (str(msg.payload).replace("'", "").replace("b",  ""))
    ]

    cursor.executemany(com_sql, valor)
    try:
        conexao.commit()
        print(cursor.rowcount, "Inserida com sucesso no Banco de Dados")
    except:
        conexao.rollback()
        print("não deu pra salvar no banco de dados :(")

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("127.0.0.1", 1883)

# Blocking call that processes network traffic, dispatches callbacks and
# handles reconnecting.
# Other loop*() functions are available that give a threaded interface and a
# manual interface.
try:
    client.loop_forever()
except KeyboardInterrupt:
    print("Não deu :/")