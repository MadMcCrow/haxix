#  tool to get all the versions of the different packages
import json, requests
try : 
    from rich import print
except :
    pass

def release(owner, repo) :
    url = f'https://github.com/{owner}/{repo}/releases/latest'
    r = requests.get(url)
    version = r.url.split('/')[-1]
    return version

def haxelib(owner, repo) :
    url = f'https://raw.githubusercontent.com/{owner}/{repo}/master/haxelib.json'
    r = requests.get(url)
    try :
        haxelib = r.json()
        return haxelib['version']
    except :
        return(f'{url}: {r.text}')
    

if __name__ == "__main__" :
    print(f'latests versions of packages :')
    print(f'haxe : {release("HaxeFoundation", "haxe")}')
    print(f'dox : {haxelib("HaxeFoundation","dox")}')
    print(f'format : {haxelib("HaxeFoundation","format")}')
    print(f'hxcpp : {haxelib("HaxeFoundation", "hxcpp")}')
    print(f'hashlink : {release("HaxeFoundation", "hashlink")}')
    print(f'heaps.io : {haxelib("HeapsIO", "heaps")}')
    print(f'haxefmt : {haxelib("HaxeCheckstyle", "haxe-formatter")}')
    print(f'raylib : {release("Raysan5", "raylib")}')
    print(f'raylib-hx : {haxelib("foreignsasquatch","raylib-hx")}')
    print(f'hxp : {haxelib("openfl","hxp")}' )
    print(f'lime : {release("openfl","lime")}')