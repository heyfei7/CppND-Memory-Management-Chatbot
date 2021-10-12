#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot cb)
{
    _chatBot = std::move(cb);
    std::cout << "GraphNode::MoveChatbotHere middle " << std::endl;
    _chatBot.SetCurrentNode(this);
    std::cout << "GraphNode::MoveChatbotHere end " << this << std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    std::cout << "GraphNode::MoveChatbotToNewNode " << newNode << std::endl;
    newNode->MoveChatbotHere(_chatBot);
    std::cout << "GraphNode::MoveChatbotToNewNode end " << newNode << std::endl;
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}