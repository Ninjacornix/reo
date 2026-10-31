"""Server subprocess entry; numeric binding avoids macOS reverse-DNS stalls."""
from pathlib import Path
import runpy
import socketserver
import sys


def run(source, arguments):
    source=Path(source)
    sys.path.insert(0,str(source))
    import werkzeug.serving
    class NumericThreadedServer(werkzeug.serving.ThreadedWSGIServer):
        def server_bind(self):
            # HTTPServer.server_bind performs an unnecessary reverse lookup.
            # Only our explicitly configured IPv4 listeners use this subclass.
            socketserver.TCPServer.server_bind(self)
            self.server_name=self.server_address[0]
            self.server_port=self.server_address[1]
    werkzeug.serving.ThreadedWSGIServer=NumericThreadedServer
    sys.argv=[str(source/'run.py'),*arguments]
    runpy.run_path(str(source/'run.py'),run_name='__main__')
