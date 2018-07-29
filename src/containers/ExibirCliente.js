import React, { Component, PropTypes } from "react";
import { connect } from "react-redux";
import { fetchCliente, deleteCliente } from "../actions/clientes";
import { Link } from "react-router-dom";

class ExibirCliente extends Component {
    componentWillMount() {
        if (!this.props.clientes) {
            // grab post id from route params
            const { id } = this.props.match.params;
            this.props.fetchCliente(id);
        }
    }

    onDeleteClick() {
        // get post id from route params
        const { id } = this.props.match.params;
        this.props.deleteCliente(id, () => {
            // post was deleted.
            // navigate user to new path
            this.props.history.push("/clientes");
        });
    }

    render() {
        const { clientes } = this.props;

        if (!clientes) {
            return <div>Loading...</div>;
        }

        return (
            <div>
                <Link to="/">Back To Index</Link>
                <button
                    className="btn btn-danger pull-xs-right"
                    onClick={this.onDeleteClick.bind(this)}>
                    Delete Post
                </button>
                <h3>{clientes.nome}</h3>
                <p>Endereço: {clientes.endereco}</p>
                <p>{clientes.telefone}</p>
                <p>{clientes.dataNasc}</p>
            </div>
        );
    }
}

function mapStateToProps(state, ownProps) {
    // react-router changed props and nested params in props.match
    return { clientes: state.clientes[ownProps.match.params.id] };
}

export default connect(
    mapStateToProps,
    { fetchCliente, deleteCliente }
)(ExibirCliente);
