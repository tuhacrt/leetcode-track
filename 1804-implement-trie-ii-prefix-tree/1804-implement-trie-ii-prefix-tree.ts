class TrieNode {
    links;
    end: number;
    start: number;

    constructor(){
        this.links = Array.from({length:26}, () => null);
        this.end = 0;
        this.start = 0;
    }
}

const at = (x: string) => x.charCodeAt(0) - 'a'.charCodeAt(0);

class Trie {
    root: TrieNode;

    constructor() {
        this.root = new TrieNode();
    }

    insert(word: string): void {
        let node = this.root;
        for (const w of word) {
            const idx = at(w);
            if (!node.links[idx]) node.links[idx] = new TrieNode();
            node = node.links[idx];
            node.start++;
        }
        node.end++;
    }

    countWordsEqualTo(word: string): number {
        let node = this.root;
        for (const w of word) {
            const idx = at(w);
            if (!node.links[idx]) return 0;
            node = node.links[idx];
        }
        return node.end;
    }

    countWordsStartingWith(prefix: string): number {
        let node = this.root;
        for (const w of prefix) {
            const idx = at(w);
            if (!node.links[idx]) return 0;
            node = node.links[idx];
        }
        return node.start;
    }

    erase(word: string): void {
        let node = this.root;
        for (const w of word) {
            const idx = at(w);
            node = node.links[idx];
            node.start--;
        }
        node.end--;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.countWordsEqualTo(word)
 * var param_3 = obj.countWordsStartingWith(prefix)
 * obj.erase(word)
 */