#Teste de README file

git Init: Inicializa um projeto com git

git add (nome_do_arquivo): adiciona as alterações do arquivo para fazer o commit

git commit -m "nome do commit": comando para realizar o commit na branch atual

git log: mostra o registro dos commits

git status: mostra o estado de alterações da branch

git diff: mostra o que foi alterado nos arquivos

git merge: mescla as branches

git branch: mostra a branch atual e lista todas as branches

git branch -b (nome da branch): comando para criar uma nova branch

git checkout (nome da branch): comando para ir para outra branch

git remote add (nome do remote) (url): adiciona um novo repositório remoto

git push (nome do remote) (nome da branch): manda as alterações locais para o repositório remoto

git pull (nome do remote) (nome da branch): pega as alterações do repositório remoto e coloca no diretório local

git fetch: atualiza o histórico local de acordo com o histórico salvo no repositório remoto

git merge -s ours (nome da branch): O comando acima informa ao Git que, em caso de conflito, a versão da branch atual (master) deve ser mantida. Isso apenas ajusta o histórico de commits, mas não altera os arquivos ainda.

git checkout (nome da branch) -- . :Copia todo o conteúdo de (nome da branch) para a branch atual

git branch -d (nome da branch): Deleta a branch (nome da branch) se ela foi mesclada
git branch -D (nome da branch): Deleta a branch (nome da branch) se ela não foi mesclada
git push origin --delete (nome da branch) : Deleta a branch no repositório remoto



comentário
