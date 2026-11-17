"""Python mirror of launcher/AutomaticAccount.cs for harness sessions (loopback test server only)."""
import os, re, secrets, string, struct, sys, time, urllib.parse, urllib.request

session = sys.argv[1]
players = int(sys.argv[2]) if len(sys.argv) > 2 else 2
deadline = time.time() + (float(sys.argv[3]) if len(sys.argv) > 3 else 600)
endpoint = 'http://127.0.0.1:10128/reweb/signup/create_id.html'
import json
users = [pl['environment']['REO_COOP_USERNAME'] for pl in json.load(open(os.path.join(session, 'config.json')))['players']]
state = {n: {'attempt': 0, 'password': None, 'delivered': 0, 'pos': 0} for n in range(1, players + 1)}


def publish(status, value):
    open(status + '.tmp', 'w').write(value)
    os.replace(status + '.tmp', status)


def register(user, password):
    body = urllib.parse.urlencode({'username': user, 'password': password}).encode()
    html = urllib.request.urlopen(urllib.request.Request(endpoint, data=body), timeout=10).read(65537).decode('utf8', 'replace')
    ok = '<!--AM-USA-COMP-SIGNUP-->' in html and f'<!--INPUT-IDS-->{user}<!--INPUT-IDE-->' in html
    if not ok:
        raise RuntimeError('registration not confirmed: ' + ('name taken' if 'Password mismatch' in html else html[:200]))


while time.time() < deadline and any(s['delivered'] < 1 for s in state.values()):
    for n, s in state.items():
        d = os.path.join(session, f'player{n}')
        status = os.path.join(d, 'account-status')
        log = os.path.join(d, 'logs', 'stderr.log')
        if not os.path.exists(log):
            continue
        with open(log, 'rb') as f:
            f.seek(s['pos']); chunk = f.read(); s['pos'] += len(chunk)
        text = chunk.decode('utf8', 'replace')
        for m in re.finditer(r'\[COOP-AUTO\] account-request (\d+)', text):
            k = int(m.group(1))
            if k > s['attempt']:
                s['attempt'] = k
                user = users[n - 1]
                pw = ''.join(secrets.choice(string.ascii_letters + string.digits) for _ in range(15))
                register(user, pw)
                s['password'] = pw
                publish(status, f'ready {k}')
                print(f'p{n} registered {user}, ready {k}', flush=True)
        for m in re.finditer(r'\[COOP-AUTO\] password-ready (\d+)', text):
            k = int(m.group(1))
            if k == s['attempt'] and s['password']:
                data = struct.pack('<III', 0x52454F41, k, 15) + s['password'].encode() + bytes(1)
                inp = status + '.credential'
                open(inp + '.tmp', 'wb').write(data); os.replace(inp + '.tmp', inp)
                publish(status, f'input {k}')
                t = time.time()
                while time.time() - t < 20:
                    ap = status + '.applied'
                    if os.path.exists(ap) and open(ap).read().strip() == str(k):
                        publish(status, f'typed {k}'); s['delivered'] = k; s['password'] = None
                        print(f'p{n} typed {k}', flush=True); break
                    time.sleep(0.025)
                else:
                    print(f'p{n} credential not applied', flush=True)
                try: os.remove(inp)
                except OSError: pass
    time.sleep(0.1)
print('broker done', {n: s['delivered'] for n, s in state.items()})
