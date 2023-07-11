"""."""
import subprocess


def test_basic_configuration():
    """."""
    ret = False
    out = ''
    try:
        out = subprocess.check_output(
            'docker compose -f basic_configuration.yml up',
            stderr=subprocess.STDOUT,
            shell=True,
            timeout=30
        ).decode().split('\n')

        sent = 0
        received = 0
        for line in out:
            if 'SENT' in line:
                sent += 1
                continue

            if 'RECEIVED' in line:
                received += 1
                continue

        if sent * 2 == received:
            ret = True
    except subprocess.CalledProcessError:
        print(l for l in out)
    except subprocess.TimeoutExpired:
        print('TIMEOUT')

    assert(ret)
