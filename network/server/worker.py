"""Shared launcher service worker; never imports any launcher UI toolkit."""
from pathlib import Path
import runpy
import socketserver
import sys

def main():
    arguments=sys.argv[1:]
    if arguments and arguments[0]=='--server-worker':arguments=arguments[1:]
    if len(arguments)<2:raise SystemExit('Usage: worker.py --server-worker SERVER_DIRECTORY SERVICE [ARGS]')
    source=Path(arguments[0]).resolve()
    sys.path.insert(0,str(source))
    import werkzeug.serving
    class NumericThreadedServer(werkzeug.serving.ThreadedWSGIServer):
        def server_bind(self):
            socketserver.TCPServer.server_bind(self)
            self.server_name=self.server_address[0]
            self.server_port=self.server_address[1]
    werkzeug.serving.ThreadedWSGIServer=NumericThreadedServer
    sys.argv=[str(source/'run.py'),*arguments[1:]]
    runpy.run_path(str(source/'run.py'),run_name='__main__')

if __name__=='__main__':main()
