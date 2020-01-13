import socket
import logging
import argparse
from threading import Thread, Event, Lock
import time

DEFAULT_FILE_NAME = 'matrix_test.txt'
DEFAULT_TARGET_IP = 'localhost'
DEFAULT_TARGET_PORT = 5600
DEFAULT_MAX_BACKLOG_SIZE = 5
DEFAULT_BUFFER_SIZE = 1024
DEFAULT_SLEEP_TIME = 0.1

logging.getLogger().setLevel(logging.INFO)

def send_and_receive():

    # connect to server
    logging.debug('Connecting to server...')
    client = socket.socket()
    client.connect((args.target_ip, args.target_port))
    logging.debug('Connected to server!')

    # read all lines from file
    with open(args.file_name) as f:
        lines = f.readlines()

    lines = [x.strip() for x in lines]
    logging.debug('Read all lines from %s', args.file_name)
    for line in lines:
        client.send(line.encode('ASCII'))
        logging.debug('Sent to server: %s', line)
        time.sleep(DEFAULT_SLEEP_TIME)

    receive_message = client.recv(DEFAULT_BUFFER_SIZE).decode('ASCII')
    logging.debug('Receive from server: %s', receive_message)
    print(receive_message)
    close_socks(client)

def close_socks(client):
    client.close()

def main():
    send_and_receive()

def set_verbosity_level():
    if args.verbose == 1:
        logging.getLogger().setLevel(logging.INFO)
    elif args.verbose == 2:
        logging.getLogger().setLevel(logging.DEBUG)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--verbose', '-v', action='count',help='Verbosity level of the output')
    parser.add_argument('--file-name', default=DEFAULT_FILE_NAME,)
    parser.add_argument('--target-ip', default=DEFAULT_TARGET_IP,)
    parser.add_argument('--target-port', default=DEFAULT_TARGET_PORT, type=int)
    parser.add_argument('--socket-backlog', default=DEFAULT_MAX_BACKLOG_SIZE, type=int)
    args = parser.parse_args()
    set_verbosity_level()
    try:
        main()
    except Exception as e:
        logging.exception(e)
