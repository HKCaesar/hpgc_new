desc "install hpgc"
task :install do 
end

desc "test"
task :test do
    num = (ENV['n'] ? ENV['n'] : '3').to_i
    mpiexec = "/opt/gcc49/openmpi/bin/mpiexec -n #{num} --allow-run-as-root"
    sh "#{mpiexec} ./build/bin/hpgc "
end

desc "Beautiful code"
task :format do
    sh './tool/astyle --options=hpgc_astyle --recursive src/*.cpp src/*.h'
end

desc 'generate protobuf file'
task :generate do
    cp_r 'src/rpc.message.proto','.'

    sh './tool/protoc --cpp_out=. rpc.message.proto'

    mv 'rpc.message.pb.h' ,'src/rpc.message.pb.h' 
    mv 'rpc.message.pb.cc','src/rpc.message.pb.cpp' 

    rm_rf 'rpc.message.proto'
end

desc "build source"
task :build do
    makedirs "build"
    cd "build"
    sh "cmake .."
    sh 'make'
    cd ".."
end

desc "clean file"
task :clean do
    rm_rf 'build'
end

desc "update file"
task :update do
    sh "git pull"
end


task :default => :test 
