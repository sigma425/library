#!/usr/bin/env python3
from atcodertools.client.models.contest import Contest
from atcodertools.client.atcoder import AtCoderClient
import sys

# write contest id here
cid = sys.argv[1]

print('Contest ID = {}'.format(cid))

try:
    at = AtCoderClient()
    at.login()
    cn = Contest(cid)
    pls = at.download_problem_list(cn)

except Exception as e:
    print('ログイン/問題取得でエラー Exception = {}'.format(e))

else:
    from subprocess import run
    from glob import glob

    run(['rm', '-r', 'tests'])
    run(['mkdir', 'tests'])

    for pl in pls:
        k = pl.alphabet
        if k == 'Ex':
            k = 'H'
        v = pl.get_url()

        try:
            smp = at.download_problem_content(pl)
        except Exception as e:
            print('{}問題で失敗 Exception = {}'.format(k, e))
        else:
            for i, tx in enumerate(smp.samples):
                fn = k + str(i) + '.in'
                f = open('tests/' + fn, 'w')
                f.write(tx.get_input())
                f.close()

                fn = k + str(i) + '.out'
                f = open('tests/' + fn, 'w')
                f.write(tx.get_output())
                f.close()
            print('Probiem {} END'.format(k))
