pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                echo 'Checking out code...'
                checkout scm
            }
        }
        stage('Build') {
            steps {
                echo 'Compiling the application...'
                sh 'gcc -o calculator calculator.c test_calculator.c -lcunit'
            }
        }
        stage('Test') {
            steps {
                echo 'Running unit tests...'
                sh './calculator > test_results.txt'
                archiveArtifacts artifacts: 'test_results.txt', allowEmptyArchive: true
            }
        }
        stage('Static Analysis') {
            steps {
                echo 'Running static analysis...'
                sh 'cppcheck --enable=all --xml . 2> cppcheck-results.xml'
                recordIssues enabledForFailure: true, tool: cppCheck(pattern: 'cppcheck-results.xml')
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying application...'
                sh './deploy.sh'
            }
        }
    }
    post {
        always {
            echo 'Cleaning up...'
            sh 'rm -rf calculator deployed test_results.txt cppcheck-results.xml'
        }
    }
}
