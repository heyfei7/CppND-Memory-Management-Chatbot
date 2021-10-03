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

GraphEdge *GraphNode::AddEdgeToChildNode(GraphEdge &&edge)
{
    _childEdges.push_back(std::make_unique<GraphEdge>(edge));
    return (_childEdges.end() - 1)->get();
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot &&cb)
{
    if (!_chatBot)
    {
        _chatBot = std::make_unique<ChatBot>(std::move(cb));
    }
    else
    {
        *_chatBot = std::move(cb);
    }
    _chatBot->GetChatLogicHandle()->SetChatbotHandle(_chatBot.get());
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(*_chatBot));
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