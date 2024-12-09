---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\nfrom atcodertools.client.models.contest import Contest\n\
    from atcodertools.client.atcoder import AtCoderClient\nimport sys\n\n# write contest\
    \ id here\ncid = sys.argv[1]\n\nprint('Contest ID = {}'.format(cid))\n\ntry:\n\
    \    at = AtCoderClient()\n    at.login()\n    cn = Contest(cid)\n    pls = at.download_problem_list(cn)\n\
    \nexcept Exception as e:\n    print('\u30ED\u30B0\u30A4\u30F3/\u554F\u984C\u53D6\
    \u5F97\u3067\u30A8\u30E9\u30FC Exception = {}'.format(e))\n\nelse:\n    from subprocess\
    \ import run\n    from glob import glob\n\n    run(['rm', '-r', 'tests'])\n  \
    \  run(['mkdir', 'tests'])\n\n    for pl in pls:\n        k = pl.alphabet\n  \
    \      if k == 'Ex':\n            k = 'H'\n        v = pl.get_url()\n\n      \
    \  num_trial = 10\n        smp = None\n        for t in range(num_trial):\n  \
    \          try:\n                smp = at.download_problem_content(pl)\n     \
    \           break\n            except Exception as e:\n                if t ==\
    \ num_trial-1:\n                    print('{}\u554F\u984C\u3067\u5931\u6557 Exception\
    \ = {}'.format(k, e))\n                continue\n        for i, tx in enumerate(smp.samples):\n\
    \            fn = k + str(i) + '.in'\n            f = open('tests/' + fn, 'w')\n\
    \            f.write(tx.get_input())\n            f.close()\n\n            fn\
    \ = k + str(i) + '.out'\n            f = open('tests/' + fn, 'w')\n          \
    \  f.write(tx.get_output())\n            f.close()\n        print('Probiem {}\
    \ END'.format(k))\n"
  dependsOn: []
  isVerificationFile: false
  path: sample_collector.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: sample_collector.py
layout: document
redirect_from:
- /library/sample_collector.py
- /library/sample_collector.py.html
title: sample_collector.py
---
